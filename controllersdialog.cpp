#include "controllersdialog.h"
#include "newcontrollerdialog.h"

controllersDialog::controllersDialog(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
    this->setWindowTitle("Controladores");
    submitButton->setText("Nuevo...");
    revertButton->setText("Borrar");
    label->setText("Direccion");
    label_2->setText("Tipo");
    label_3->setText("Estado");
    nameEdit->setEnabled(false);

    model = new QSqlTableModel;
    model->setTable("controllers");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->addMapping(nameEdit, model->fieldIndex("controllerAddress"));
    mapper->addMapping(controllerEdit, model->fieldIndex("controllerType"));

    connect(previousButton, SIGNAL(clicked()), mapper, SLOT(toPrevious()));
    connect(nextButton, SIGNAL(clicked()), mapper, SLOT(toNext()));
    connect(mapper, SIGNAL(currentIndexChanged(int)), this, SLOT(updateButtons(int)));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(addController()));
    connect(revertButton, SIGNAL(clicked()), this, SLOT(deleteController()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
}

void controllersDialog::updateButtons(int row)
{
    previousButton->setEnabled(row > 0);
    nextButton->setEnabled(row < model->rowCount() - 1);
    emit controllerChanged(nameEdit->text().toInt());
}

void controllersDialog::updateControllerStatus(QString Status)
{
    positionEdit->setText(Status);
}

void controllersDialog::submit()
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

void controllersDialog::addController()
{
    newControllerDialog dlg(this);

    if(dlg.exec() == QDialog::Accepted){
        //Obteniendo la direccion del nuevo controlador
        QString addressStr = dlg.getAddress();
        int controllerAddress = addressStr.toInt();

        //Discriminando por tipo de controlador
        if(dlg.getType() == 0){  //Se trata de un controlador de puertas
            //Insertando el nuevo controlador de puertas en la base de datos
            QSqlField address("controllerAddress", QVariant::Int);
            address.setValue(QVariant(controllerAddress));
            QSqlField type("controllerType", QVariant::String);
            type.setValue(QVariant("doors"));
            QSqlRecord controllerRecord;
            controllerRecord.append(address);
            controllerRecord.append(type);
            model->insertRecord(-1, controllerRecord);
            submit();

            //Insertando las puertas del nuevo controlador en la base de datos
            QSqlTableModel doorsModel;
            doorsModel.setTable("doors");
            doorsModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
            doorsModel.select();

            QSqlField doorName("name", QVariant::String);
            QSqlField doorPosition("position", QVariant::Int);

            //Insertando la primera puerta
            QString firstDoorName = "Controller" + addressStr + "firstDoor";
            doorName.setValue(QVariant(firstDoorName));
            doorPosition.setValue(QVariant(1));
            QSqlRecord firstDoorRecord;
            firstDoorRecord.append(doorName);
            firstDoorRecord.append(address);
            firstDoorRecord.append(doorPosition);
            doorsModel.insertRecord(-1, firstDoorRecord);

            //Insertando la segunda puerta
            QString secondDoorName = "Controller" + addressStr + "secondDoor";
            doorName.setValue(QVariant(secondDoorName));
            doorPosition.setValue(QVariant(2));
            QSqlRecord secondDoorRecord;
            secondDoorRecord.append(doorName);
            secondDoorRecord.append(address);
            secondDoorRecord.append(doorPosition);
            doorsModel.insertRecord(-1, secondDoorRecord);

            doorsModel.database().transaction();
            if (doorsModel.submitAll())
                doorsModel.database().commit();
            else {
                doorsModel.database().rollback();
                QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(doorsModel.lastError().text()));
            }

            mapper->toFirst();
        }
        else{   //Se trata de un controlador de entradas/salidas
            //Insertando el nuevo controlador de entradas/salidas en la base de datos
            QSqlField address("controllerAddress", QVariant::Int);
            address.setValue(QVariant(controllerAddress));
            QSqlField type("controllerType", QVariant::String);
            type.setValue(QVariant("in_outs"));
            QSqlRecord controllerRecord;
            controllerRecord.append(address);
            controllerRecord.append(type);
            model->insertRecord(-1, controllerRecord);
            submit();

            //Insertando las 8 entradas del nuevo controlador en la base de datos
            QSqlTableModel insModel;
            insModel.setTable("ins");
            insModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
            insModel.select();

            QSqlField inName("name", QVariant::String);
            QSqlField inPosition("position", QVariant::Int);

            for(int i = 1; i <= 8; i++){
                QString positionStr;
                QString inNameStr = "Controller" + addressStr + "In" + positionStr.setNum(i);
                inName.setValue(QVariant(inNameStr));
                inPosition.setValue(QVariant(i));
                QSqlRecord inRecord;
                inRecord.append(inName);
                inRecord.append(address);    //La direccion del controlador
                inRecord.append(inPosition);
                insModel.insertRecord(-1, inRecord);
            }

            insModel.database().transaction();
            if (insModel.submitAll())
                insModel.database().commit();
            else {
                insModel.database().rollback();
                QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(insModel.lastError().text()));
            }

            //Insertando las 8 salidas del nuevo controlador en la base de datos
            QSqlTableModel outsModel;
            outsModel.setTable("outs");
            outsModel.setEditStrategy(QSqlTableModel::OnManualSubmit);
            outsModel.select();

            QSqlField outName("name", QVariant::String);
            QSqlField outPosition("position", QVariant::Int);

            for(int i = 1; i <= 8; i++){
                QString positionStr;
                QString outNameStr = "Controller" + addressStr + "Out" + positionStr.setNum(i);
                outName.setValue(QVariant(outNameStr));
                outPosition.setValue(QVariant(i));
                QSqlRecord outRecord;
                outRecord.append(outName);
                outRecord.append(address);    //La direccion del controlador
                outRecord.append(outPosition);
                outsModel.insertRecord(-1, outRecord);
            }

            outsModel.database().transaction();
            if (outsModel.submitAll())
                outsModel.database().commit();
            else {
                outsModel.database().rollback();
                QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(outsModel.lastError().text()));
            }

            mapper->toFirst();
        }
    }
}

void controllersDialog::deleteController()
{
    if(model->removeRow(mapper->currentIndex())){
        submit();
        mapper->toFirst();
    }
    else
        QMessageBox::warning(this, tr("Cached Table"), tr("The database reported an error: %1").arg(model->lastError().text()));
}




