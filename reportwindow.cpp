#include "reportwindow.h"
#include <QDateTime>

ReportWindow::ReportWindow(TDataManager *_dataManager, QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    dataManager = _dataManager;

    connect(pushButton, SIGNAL(clicked()), this, SLOT(generateReports()));
    connect(actionImprimir, SIGNAL(activated()), this, SLOT(printReports()));

}

void ReportWindow::generateReports()
{
    //reports.clear();
    reports = dataManager->getReports(inicialTimeEdit->dateTime(), finalTimeEdit->dateTime());
    reportsTableWidget->clear();
    reportsTableWidget->setRowCount(reports.count());
    reportsTableWidget->setColumnCount(6);

    tableLabels.append("Fecha");
    tableLabels.append("Hora");
    tableLabels.append("Evento");
    tableLabels.append("Lugar");
    tableLabels.append("Nombre");
    tableLabels.append("Apellido");
    reportsTableWidget->setHorizontalHeaderLabels(tableLabels);

    for(int row = 0; row < reports.count(); row++){
        for(int column = 0; column < 6; column++){
            QTableWidgetItem *newItem = new QTableWidgetItem(reports[row][column]);
            reportsTableWidget->setItem(row, column, newItem);
        }
    }
}

/*ReportWindow::~ReportWindow()
{
    delete ui;
}*/

void ReportWindow::printReports()
{
    QPrinter *printer = new QPrinter;
    QPrintDialog printDialog(printer, this);
    if (printDialog.exec() == QDialog::Accepted){
        QTextDocument *textDocument = new QTextDocument(this);
        QTextCursor *cursor= new QTextCursor(textDocument);
        cursor->setPosition(0);

        QTextTableFormat tableFormat;
        tableFormat.setAlignment(Qt::AlignHCenter);
        tableFormat.setCellPadding(2);
        tableFormat.setCellSpacing(0);

        QTextTable *table = cursor->insertTable(reports.count() + 1, 6, tableFormat);

        QTextFrame *frame = cursor->currentFrame();
        QTextFrameFormat frameFormat = frame->frameFormat();
        frameFormat.setBorder(1);
        frame->setFrameFormat(frameFormat);

        QTextCharFormat format = cursor->charFormat();
        format.setFontPointSize(10);

        QTextCharFormat boldFormat = format;
        boldFormat.setFontWeight(QFont::Bold);

        QTextCharFormat highlightedFormat = boldFormat;
        highlightedFormat.setBackground(Qt::yellow);

        //Insertando los titulos de las columnas
        for (int i = 0; i < 6; i++){
            QTextTableCell cell = table->cellAt(0, i);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(tableLabels[i], boldFormat);
        }

        //Insertando el contenido de la tabla
        for(int row = 0; row < reports.count(); row++){
            for(int column = 0; column < 6; column++){
                QTextTableCell cell = table->cellAt(row + 1, column);
                QTextCursor cellCursor = cell.firstCursorPosition();
                cellCursor.insertText(reports[row][column]);
            }
        }

        textDocument->print(printer);
    }
}





