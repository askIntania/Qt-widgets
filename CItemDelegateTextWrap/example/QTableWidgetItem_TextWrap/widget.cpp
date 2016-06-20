#include "widget.h"
#include "ui_widget.h"
#include "../../src/citemdelegatetextwrap.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CItemDelegateTextWrap *itemDelegate = new CItemDelegateTextWrap(ui->tableWidget);
    itemDelegate->setPaddingX(10);
    ui->tableWidget->setItemDelegate(itemDelegate);

    for(int i=0; i<ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem *item0 = new QTableWidgetItem();
        item0->setTextColor(QColor(Qt::red));
        item0->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        item1->setTextColor(QColor(Qt::green));
        item1->setTextAlignment(Qt::AlignCenter | Qt::TextWordWrap);
        ui->tableWidget->setItem(i, 1, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem();
        item2->setTextColor(QColor(Qt::blue));
        item2->setTextAlignment(Qt::AlignCenter | Qt::TextWrapAnywhere);
        ui->tableWidget->setItem(i, 2, item2);
    }
}

Widget::~Widget()
{
    delete ui;
}
