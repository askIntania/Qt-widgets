#include "citemdelegatetextwrap.h"
#include <QTableWidgetItem>
#include <QPainter>

CItemDelegateTextWrap::CItemDelegateTextWrap(QObject *parent):
    QStyledItemDelegate( parent )
{
    paddingX = 0;
}

void CItemDelegateTextWrap::initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const
{
    QStyledItemDelegate::initStyleOption(option, index);
}

void CItemDelegateTextWrap::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    opt.rect.adjust(paddingX, 0, -paddingX, 0);

    Qt::Alignment alignment = (Qt::Alignment)index.data(Qt::TextAlignmentRole).toInt();

    if(alignment & Qt::TextWordWrap){
        QStyledItemDelegate::paint( painter, opt, index );
    }
    else{
        painter->save();
        painter->setPen  ( QPen  ( index.data(Qt::ForegroundRole).value<QBrush>().color() ) );
        painter->setBrush( QBrush( index.data(Qt::BackgroundRole).value<QBrush>()         ) );
        painter->setFont ( QFont ( index.data(Qt::FontRole).value<QFont>()                ) );
        painter->drawText( opt.rect, alignment, index.data(Qt::DisplayRole).toString() );
        painter->restore();
    }
}

void CItemDelegateTextWrap::setPaddingX(const int x)
{
    paddingX = x;
}
