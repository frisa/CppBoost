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
