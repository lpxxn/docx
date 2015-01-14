#include "oxml.h"

using namespace Docx;

BaseOxmlElement::BaseOxmlElement()
    : QDomDocument()
{

}

BaseOxmlElement::~BaseOxmlElement()
{

}


// CT_Default start

CT_Default::CT_Default()
    : QDomElement()
{

}

CT_Default::CT_Default(const QDomElement &x)
    : QDomElement(x)
{

}

QString CT_Default::contentType()
{
    return this->attribute("ContentType");
}

QString CT_Default::extension()
{
    return this->attribute("Extension");
}

CT_Default CT_Default::newDefault(const QString &ext, const QString &content_type)
{
    QDomDocument docment;
    CT_Default defXml = CT_Default(docment.createElement("Default"));
    defXml.setAttribute("Extension", ext);
    defXml.setAttribute("ContentType", content_type);
    return defXml;
}

CT_Default::~CT_Default()
{

}



// CT_Override start

CT_Override::CT_Override()
    : QDomElement()
{

}

CT_Override::CT_Override(const QDomElement &x)
    : QDomElement(x)
{

}

QString CT_Override::contentType()
{
    return this->attribute("ContentType");
}

QString CT_Override::partname()
{
    return this->attribute("PartName");
}

CT_Override CT_Override::newOverride(const QString &partname, const QString &content_type)
{
    QDomDocument docment;
    CT_Override ovXml = CT_Override(docment.createElement("Override"));
    ovXml.setAttribute("PartName", partname);
    ovXml.setAttribute("ContentType", content_type);
    return ovXml;
}

CT_Override::~CT_Override()
{

}

// CT_Relationship

RELATIONSHIP_TARGET_MODE rtm;

CT_Relationship::CT_Relationship()
    : QDomElement()
{

}

CT_Relationship::CT_Relationship(const QDomElement &x)
    : QDomElement(x)
{

}

CT_Relationship CT_Relationship::newRelationship(const QString &rId, const QString &reltype
                                         , const QString &target, const QString &target_mode)
{
    QDomDocument docment;
    CT_Relationship eleXml = CT_Relationship(docment.createElement("Relationship"));
    eleXml.setAttribute("Id", rId);
    eleXml.setAttribute("Type", reltype);
    eleXml.setAttribute("Target", target);
    if (target_mode == rtm.EXTERNAL)
        eleXml.setAttribute("TargetMode", rtm.EXTERNAL);
    return eleXml;
}

QString CT_Relationship::rId()
{
    return this->attribute("Id");
}

QString CT_Relationship::relType()
{
    return this->attribute("Type");
}

QString CT_Relationship::targetRef()
{
    return this->attribute("Target");
}

QString CT_Relationship::targetMode()
{
    return this->attribute("TargetMode", rtm.INTERNAL);
}

CT_Relationship::~CT_Relationship()
{

}

// ReltionShips begin

CT_Relationships::CT_Relationships()
    : QDomElement()
{

}

CT_Relationships::CT_Relationships(const QDomElement &x)
    : QDomElement(x)
{

}

CT_Relationships CT_Relationships::newRelationships()
{
    QDomDocument docment;
    CT_Relationships eleXml = CT_Relationships(docment.createElement("Relationships"));

    return eleXml;
}

void CT_Relationships::RelationshipLst()
{
    this->toDocument().elementsByTagName("Relationship");
}

CT_Relationships::~CT_Relationships()
{

}
