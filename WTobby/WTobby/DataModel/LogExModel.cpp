#include "LogExModel.h"

QHash<int, QByteArray> LogExModel::roleNames() const
{
    static QHash<int, QByteArray> *roles;
    if (!roles)
    {
        roles = new QHash<int, QByteArray>();
        (*roles)[TypeRole] = "type";
        (*roles)[MessageRole] = "message";
    }
    return *roles;
}

LogExModel::LogExModel(QObject* parent): QAbstractListModel(parent)
{
}

void LogExModel::addMessage(QString type, QString message)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _data << LogExDataObject(type, message);
    endInsertRows();
}

Q_INVOKABLE void LogExModel::increment()
{
    static int inc = 0;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    _data << LogExDataObject("I", QStringLiteral("i: %1").arg(++inc));
    endInsertRows();
}

Q_INVOKABLE int LogExModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
	return _data.size();
}

Q_INVOKABLE QVariant LogExModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == LogRoles::MessageRole)
    {
        return _data[index.row()].message();
    }
    else if (role == LogRoles::TypeRole)
    {
        return _data[index.row()].type();
    }
    else
    {
        return QVariant();
    }
}
