#include "accesslevelwindow.h"

accessLevelWindow::accessLevelWindow(TDataManager *_dataManager, QWidget *parent) : QWidget(parent)
{
    setupUi(this);

    dataManager = _dataManager;

    model = new QSqlTableModel();
    model->setTable("accessLevels");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit, model->fieldIndex("name"));
    mapper->toFirst();

    refreshListWidget();

    connect(previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
    connect(addDoorButton, SIGNAL(clicked()), this, SLOT(addAccessLevelDoor()));
    connect(deleteDoorButton, SIGNAL(clicked()), this, SLOT(removeAccessLevelDoor()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(revertButton, SIGNAL(clicked()), this, SLOT(revert()));
    connect(newButton, SIGNAL(clicked()), this, SLOT(addAccessLevel()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteAccessLevel()));


}

void accessLevelWindow::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
    refreshListWidget();
}

void accessLevelWindow::addAccessLevelDoor()
{
    QList<QListWidgetItem*> list = doorListWidget->selectedItems();
    for(int i = 0; i < list.count(); i++){
        accessDoorList.append(list[i]->text());
    }
    refreshWidget();
}

void accessLevelWindow::removeAccessLevelDoor()
{
    QList<QListWidgetItem*> list = accessDoorListWidget->selectedItems();
    for(int i = 0; i < list.count(); i++){
        accessDoorList.removeOne(list[i]->text());
        doorList.append(list[i]->text());
    }
    refreshWidget();
}

void accessLevelWindow::refreshListWidget()
{
    accessDoorList = dataManager->getAccessLevelDoorList(nameEdit->text());
    doorList = dataManager->getDoorNameList();
    refreshWidget();
}

void accessLevelWindow::refreshWidget()
{
    accessDoorListWidget->clear();
    for(int i = 0; i < accessDoorList.count(); i++){
        accessDoorListWidget->addItem(accessDoorList[i]);
        if(doorList.contains(accessDoorList[i]))
            doorList.removeOne(accessDoorList[i]);
    }

    doorListWidget->clear();
    doorListWidget->addItems(doorList);
}

void accessLevelWindow::submit()
{
    submitDB();
    dataManager->updateAccessLevelDoorTable(dataManager->getAccessLevelID(nameEdit->text()), dataManager->getDoorsID(accessDoorList));
    mapper->toFirst();
}

void accessLevelWindow::submitDB()
{
    model->database().transaction();
    if (model->submitAll())
        model->database().commit();
    else {
        model->database().rollback();
        QMessageBox::warning(this, tr("MiniPass"), tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}

void accessLevelWindow::revert()
{
    model->revertAll();
    refreshListWidget();
}

void accessLevelWindow::addAccessLevel()
{
    QSqlRecord record;
    model->insertRecord(-1, record);
    mapper->toLast();
    nameEdit->setText("nuevo");
    refreshListWidget();
}

void accessLevelWindow::deleteAccessLevel()
{
    if(model->removeRow(mapper->currentIndex())){
        submitDB();
        mapper->toFirst();
    }
    else
        QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(model->lastError().text()));
}


