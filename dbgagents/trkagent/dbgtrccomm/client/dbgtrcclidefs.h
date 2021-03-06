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

#ifndef __DbgTrcCliDefs_h__
#define __DbgTrcCliDefs_h__

// System includes
#include <e32base.h>
// User includes

// Type definitions

// Constants

// Enumerations


//
// DbgTrcCliDefs (header)
//

//This is a utility class that retrieves the name and version number of the DbgTrcServer 
class DbgTrcCliDefs
{
	// STATIC ACCESS METHODS
	public:										
		static const TDesC&	ServerAndThreadName();

		static const TDesC&	ServerImageName();

		static TUidType		ServerUid();

		static TVersion		Version();

};

#endif //__DbgTrcCliDefs_h__

