#include "insdialog.h"

insDialog::insDialog(TDataManager *_dataManager, QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    dataManager = _dataManager;

    model = new QSqlTableModel;
    model->setTable("ins");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit, model->fieldIndex("name"));
    mapper->addMapping(controllerEdit, model->fieldIndex("controllerAddress"));
    mapper->addMapping(positionEdit, model->fieldIndex("position"));

    refreshListWidget();

    connect(previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(addOutButton, SIGNAL(clicked()), this, SLOT(addActivatedOut()));
    connect(deleteOutButton, SIGNAL(clicked()), this, SLOT(removeActivatedOut()));
}

void insDialog::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
    refreshListWidget();
}

void insDialog::submit()
{
    submitDB();
    //qDebug() << activatedOutList;
    dataManager->updateInOutTable(dataManager->getInID(nameEdit->text()), dataManager->getOutsID(activatedOutList));
    mapper->toFirst();
    //submitDB();
}

void insDialog::submitDB()
{
    model->database().transaction();
    if (model->submitAll())
        model->database().commit();
    else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
    //mapper->toFirst();
}

void insDialog::revert()
{
    model->revertAll();
    refreshListWidget();
}


void insDialog::refreshListWidget()
{
    activatedOutList = dataManager->getActivatedOutList(nameEdit->text());
    outList = dataManager->getOutNameList();
    refreshWidget();
}

void insDialog::refreshWidget()
{
    activatedOutListWidget->clear();
    for(int i = 0; i < activatedOutList.count(); i++){
        activatedOutListWidget->addItem(activatedOutList[i]);
        if(outList.contains(activatedOutList[i]))
            outList.removeOne(activatedOutList[i]);
    }

    noActivatedOutListWidget->clear();
    noActivatedOutListWidget->addItems(outList);
}

void insDialog::addActivatedOut()
{
    QList<QListWidgetItem*> list = noActivatedOutListWidget->selectedItems();
    for(int i = 0; i < list.count(); i++){
        activatedOutList.append(list[i]->text());
    }
    //qDebug() << activatedOutList;
    refreshWidget();
}

void insDialog::removeActivatedOut()
{
    QList<QListWidgetItem*> list = activatedOutListWidget->selectedItems();
    for(int i = 0; i < list.count(); i++){
        activatedOutList.removeOne(list[i]->text());
        outList.append(list[i]->text());
    }
    refreshWidget();
}
