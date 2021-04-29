#include "LogExModel.h"

QHash<int, QByteArray> LogExModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[MessageRole] = "message";
    return roles;
}

LogExModel::LogExModel(QObject* parent): QAbstractListModel(parent)
{
}

void LogExModel::addMessage(QString type, QString message)
{
    _data.append(LogExDataObject(type, message));
}

Q_INVOKABLE int LogExModel::rowCount(const QModelIndex&) const
{
	return _data.size();
}

Q_INVOKABLE QVariant LogExModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
            return _data[index.row()].type();
        if (index.column() == 1)
            return _data[index.row()].message();
    }
    return QVariant();
}
