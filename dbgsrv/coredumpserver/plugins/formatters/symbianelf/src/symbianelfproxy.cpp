// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#include <implementationproxy.h>

#include "symbianelfformatter.h"
#include "symbianelfformatterv2.h"

// ECom boiler template code
const TImplementationProxy ImplementationTable[] =
{
	IMPLEMENTATION_PROXY_ENTRY(0x10282fe3, CSymbianElfFormatter::NewL),
	IMPLEMENTATION_PROXY_ENTRY(0x102836bb, CSymbianElfFormatterV2::NewL)
};

EXPORT_C const TImplementationProxy* ImplementationGroupProxy(TInt& aTableCount)
{
	aTableCount = sizeof(ImplementationTable) / sizeof(TImplementationProxy);
	return ImplementationTable;
}

