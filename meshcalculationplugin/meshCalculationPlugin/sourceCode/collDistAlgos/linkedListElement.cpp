// This file is part of the MESH CALCULATION PLUGIN for V-REP
// 
// Copyright 2006-2017 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// The MESH CALCULATION PLUGIN is licensed under the terms of EITHER:
//   1. MESH CALCULATION PLUGIN commercial license (contact us for details)
//   2. MESH CALCULATION PLUGIN educational license (see below)
// 
// MESH CALCULATION PLUGIN educational license:
// -------------------------------------------------------------------
// The MESH CALCULATION PLUGIN educational license applies only to EDUCATIONAL
// ENTITIES composed by following people and institutions:
// 
// 1. Hobbyists, students, teachers and professors
// 2. Schools and universities
// 
// EDUCATIONAL ENTITIES do NOT include companies, research institutions,
// non-profit organisations, foundations, etc.
// 
// An EDUCATIONAL ENTITY may use, modify, compile and distribute the
// modified/unmodified MESH CALCULATION PLUGIN under following conditions:
//  
// 1. Distribution should be free of charge.
// 2. Distribution should be to EDUCATIONAL ENTITIES only.
// 3. Usage should be non-commercial.
// 4. Altered source versions must be plainly marked as such and distributed
//    along with any compiled code.
// 5. When using the MESH CALCULATION PLUGIN in conjunction with V-REP, the "EDU"
//    watermark in the V-REP scene view should not be removed.
// 6. The origin of the MESH CALCULATION PLUGIN must not be misrepresented. you must
//    not claim that you wrote the original software.
// 
// THE MESH CALCULATION PLUGIN IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS
// OR IMPLIED WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.4.0 rev. 1 on April 5th 2017

#include "linkedListElement.h"

CLinkedListElement::CLinkedListElement()
{
    flag=false;
    front=false;
    back=false;
    previous=NULL;
    next=NULL;
}

CLinkedListElement::CLinkedListElement(const C3Vector& v)
{
    flag=false;
    front=false;
    back=false;
    point=v;
    previous=NULL;
    next=NULL;
}

CLinkedListElement::CLinkedListElement(const C3Vector& v,CLinkedListElement* insertAfterThis)
{
    flag=false;
    front=false;
    back=false;
    point=v;
    previous=insertAfterThis;
    next=insertAfterThis->next;
    if (next==NULL) // The list has length 1 (and will have length 2)
    {
        next=previous;
        insertAfterThis->next=this;
        insertAfterThis->previous=this;
    }
    else
    {
        insertAfterThis->next->previous=this;
        insertAfterThis->next=this;
    }
}

CLinkedListElement::~CLinkedListElement()
{
    if (previous!=NULL)
    {
        if (next!=previous)
        {   // There are more than 2 elements left.
            previous->next=next;
            next->previous=previous;
        }
        else
        {   // There are 2 elements left. We remove one of them
            previous->next=NULL;
            previous->previous=NULL;
        }
    }
}
