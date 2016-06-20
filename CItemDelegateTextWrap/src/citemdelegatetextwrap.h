#ifndef CITEMDELEGATETEXTWRAP_H
#define CITEMDELEGATETEXTWRAP_H

#include <QStyledItemDelegate>
class CItemDelegateTextWrap : public QStyledItemDelegate
{
Q_OBJECT
public:
    CItemDelegateTextWrap(QObject *parent = 0);
    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const;
    void paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const;

    void setPaddingX(const int x);

private:
    int paddingX;
};

#endif // CITEMDELEGATETEXTWRAP_H
