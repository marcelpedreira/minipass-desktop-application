#include "userswindow.h"
#include <QIntValidator>

usersWindow::usersWindow(QWidget *parent) :  QWidget(parent)
{
    setupUi(this);

    model = new QSqlRelationalTableModel;
    model->setTable("users");
    int relationIndex = model->fieldIndex("accessLevelID");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(relationIndex, QSqlRelation("accessLevels", "accessLevelID", "name"));
    model->select();

    QSqlTableModel *relModel = model->relationModel(relationIndex);
    accessLevelComboBox->setModel(relModel);
    accessLevelComboBox->setModelColumn(1);

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(nameEdit, model->fieldIndex("name"));
    mapper->addMapping(lastNameEdit, model->fieldIndex("lastName"));
    mapper->addMapping(facCodeEdit, model->fieldIndex("facilityCode"));
    mapper->addMapping(userCodeEdit, model->fieldIndex("userCode"));
    mapper->addMapping(IDEdit, model->fieldIndex("userID"));
    mapper->addMapping(accessLevelComboBox, relationIndex);
    mapper->toFirst();

    QValidator *IDValidator = new QIntValidator(1, 9999, this);
    IDEdit->setValidator(IDValidator);
    QValidator *facCodeValidator = new QIntValidator(1, 255, this);
    facCodeEdit->setValidator(facCodeValidator);
    QValidator *userCodeValidator = new QIntValidator(1, 65535, this);
    userCodeEdit->setValidator(userCodeValidator);

    connect(previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    connect(newButton, SIGNAL(clicked()), this, SLOT(addUser()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteUser()));
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void usersWindow::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
}

void usersWindow::submit()
{
    model->database().transaction();
    if (model->submitAll())
        model->database().commit();
    else {
        model->database().rollback();
        QMessageBox::warning(this, tr("MiniPass"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
    mapper->toFirst();
}

void usersWindow::addUser()
{
    QSqlRecord record;
    model->insertRecord(-1, record);
    mapper->toLast();
    IDEdit->setText("1");
    accessLevelComboBox->setCurrentIndex(0);
}

void usersWindow::deleteUser()
{
    if(model->removeRow(mapper->currentIndex()))
        submit();
    else
        QMessageBox::warning(this, tr("MiniPass"), tr("The database reported an error: %1").arg(model->lastError().text()));
}


