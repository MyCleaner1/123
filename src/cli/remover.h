/****************************************************************************
**
** SVG Cleaner is batch, tunable, crossplatform SVG cleaning program.
** Copyright (C) 2013 Evgeniy Reizner
** Copyright (C) 2012 Andrey Bayrak, Evgeniy Reizner
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#ifndef REMOVER_H
#define REMOVER_H

#include "basecleaner.h"

struct DefsElemStruct
{
    SvgElement elem;
    QString tagName;
    bool hasChildren;
    StringMap attrMap;
};

class Remover : public BaseCleaner
{
public:
    explicit Remover(XMLDocument *doc);
    void removeUnreferencedIds();
    void removeUnusedDefs();
    void removeUnusedXLinks();
    void removeDuplicatedDefs();
    void removeElements();
    void cleanSvgElementAttribute();
    void removeAttributes();
    void processStyleAttr(SvgElement elem = SvgElement());
    void removeGroups();

private:
    QList<StringHash> styleHashList;
    StringHash parentHash;

    void cleanStyle(const SvgElement &elem, StringHash &hash);
    void removeDefaultValue(StringHash &hash, const QString &name);
    bool isInvisibleElementsExist(const SvgElement &elem);
    void cleanAttribute(SvgElement &elem, const QString &startWith, QStringList &attrList);
    void megreGroups(SvgElement parentElem, SvgElement childElem, bool isParentToChild);
};

#endif // REMOVER_H
