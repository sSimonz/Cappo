#ifndef CXMLLANGUAGE_H
#define CXMLLANGUAGE_H

#include <QStringList>
#include "xmllanguageid.h"

class CXmlLanguage
{
public:
    CXmlLanguage();
    ~CXmlLanguage();

    void ReadXml(const QString& strPath);
    QString LoadStringFromID(int nID);
private:
    int m_nCount;
    QStringList m_listTranslation;
};

void    InitXmlLanguage(const QString& strPath);
void    UnInitXmlLanguage();
QString LoadStringFromID(int nID);

#endif // CXMLLANGUAGE_H
