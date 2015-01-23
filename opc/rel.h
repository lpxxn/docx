#ifndef REL_H
#define REL_H

#include "packuri.h"
#include "part.h"

#include <QString>
#include <QMap>


namespace Docx {

class Relationship
{
public:
    Relationship(const QString &rId, const QString &reltype, Part *target, const QString &baseURI, bool external = false);
    QString rId() const { return m_rId; }
    QString relType() const { return m_reltype; }
    Part * target() const { return m_target; }
    QString baseURI() const { return m_baseURI; }
    bool isExternal() const { return m_isexternal; }
    virtual ~Relationship();

private:
    QString m_rId;
    QString m_reltype;
    Part *m_target;
    QString m_baseURI;
    bool m_isexternal;

};

class Relationships
{
public:
    Relationships(const QString &baseURI);
    Relationship *addRelationship(const QString &reltype, Part *target, const QString &rId, bool external = false);
    Part *partWithReltype(const QString &reltype);
    virtual ~Relationships();

private:
    QString m_baseURI;
    QMap<QString, Part *> m_targetPartsByrId;
    QMap<QString, Relationship *> m_rels;
};

}

#endif // REL_H
