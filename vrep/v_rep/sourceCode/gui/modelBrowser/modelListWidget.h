// This file is part of V-REP, the Virtual Robot Experimentation Platform.
// 
// Copyright 2006-2017 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// V-REP is dual-licensed, under the terms of EITHER (at your option):
//   1. V-REP commercial license (contact us for details)
//   2. GNU GPL (see below)
// 
// GNU GPL license:
// -------------------------------------------------------------------
// V-REP is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// V-REP IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// 
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with V-REP.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.4.0 rev. 1 on April 5th 2017

#pragma once

#include "thumbnail.h"
#include "modelListWidgetBase.h"

struct SModelThumbnailInfo
{
    CThumbnail* thumbnail;
    std::string nameWithExtension;
    std::string modelPathAndNameWithExtension; // set during a drag-and-drop motion
    unsigned int creationTime;
    unsigned char validFileFormat;
    unsigned char modelOrFolder;
    C7Vector modelTr;
    C3Vector modelBoundingBoxSize;
    float modelNonDefaultTranslationStepSize;
    C3Vector desiredDropPos; // set during a drag-and-drop motion
};

class CModelListWidget : public CModelListWidgetBase
{
    Q_OBJECT

public:
    CModelListWidget();
    virtual ~CModelListWidget();


    QMimeData* mimeData(const QList<QListWidgetItem *> items) const;
    void setFolder(const char* folderPath);

    SModelThumbnailInfo* getThumbnailInfoFromModelName(const char* nameWithExtension,int* index);
    void addThumbnail(CThumbnail* thumbN,const char* nameWithExtension,unsigned int creationTime,unsigned char modelOrFolder,bool validFileformat,C7Vector* optionalModelTr,C3Vector* optionalModelBoundingBoxSize,float* optionalModelNonDefaultTranslationStepSize);
    static CThumbnail* loadModelThumbnail(const char* pathAndFilename,int& result,C7Vector& modelTr,C3Vector& modelBoundingBoxSize,float& modelNonDefaultTranslationStepSize);
    void serializePart1(CSer& ar);
    void serializePart2(CSer& ar);

private:
    void clearAll();
    void _addThumbnailItemToList(int index);

    std::string _folderPath;
    std::vector<SModelThumbnailInfo> _allThumbnailsInfo;

signals:
    void itemClicked(QListWidgetItem* item);

private slots:
    void onItemClicked(QListWidgetItem* item);
};
