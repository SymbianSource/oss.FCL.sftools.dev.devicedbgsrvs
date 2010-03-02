/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/

#ifndef __TRKAPPLICATION_H
#define __TRKAPPLICATION_H

#include <eikapp.h>

//
//
// CTrkApplication
//
//

class CTrkApplication : public CEikApplication
{
private: 

	CApaDocument* CreateDocumentL();
	TUid AppDllUid() const;
};

#endif //__TRKAPPLICATION_H

