#include "outsdialog.h"

outsDialog::outsDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
   this->setWindowTitle("Salidas");

    model = new QSqlTableModel;
    model->setTable("outs");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit, model->fieldIndex("name"));
    mapper->addMapping(controllerEdit, model->fieldIndex("controllerAddress"));
    mapper->addMapping(positionEdit, model->fieldIndex("position"));

    connect(previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), model, SLOT(revertAll()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void outsDialog::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
}

void outsDialog::submit()
{
    model->database().transaction();
    if (model->submitAll())
        model->database().commit();
    else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
    mapper->toFirst();
}
