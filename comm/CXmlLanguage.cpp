#include "CXmlLanguage.h"
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QDebug>

static CXmlLanguage* s_pXmlLanguage = NULL;
CXmlLanguage::CXmlLanguage()
{
    m_nCount = 0;
}

CXmlLanguage::~CXmlLanguage()
{
    m_listTranslation.clear();
}

void CXmlLanguage::ReadXml(const QString& strPath)
{
    QFileInfo xmlInfo(strPath);
    Q_ASSERT(xmlInfo.exists());

    QFile xmlFile(strPath);
    if (!xmlFile.open(QIODevice::ReadOnly))
        return;

    QXmlStreamReader xmlReader(&xmlFile);
    xmlReader.readNext();
    while (!xmlReader.atEnd()) {
        if(xmlReader.isStartElement() && xmlReader.name().toString() == "string")
            m_listTranslation << xmlReader.readElementText();
        xmlReader.readNext();
    }
    xmlReader.clear();

    m_nCount = m_listTranslation.size();
}

QString CXmlLanguage::LoadStringFromID(int nID)
{
    Q_ASSERT(nID > -1 && nID < m_nCount);
    return m_listTranslation.at(nID);
}

void InitXmlLanguage(const QString& strPath)
{
    Q_ASSERT(s_pXmlLanguage == NULL);
    s_pXmlLanguage = new CXmlLanguage();
    s_pXmlLanguage->ReadXml(strPath);
}

void UnInitXmlLanguage()
{
    if (s_pXmlLanguage){
        delete s_pXmlLanguage;
        s_pXmlLanguage = NULL;
    }
}

QString LoadStringFromID(int nID)
{
    Q_ASSERT(s_pXmlLanguage);
    return s_pXmlLanguage->LoadStringFromID(nID);
}
