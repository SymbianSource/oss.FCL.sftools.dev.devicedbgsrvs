/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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


#ifndef __TRKDCCCOMM_H__
#define __TRKDCCCOMM_H__

//
// class TCapsTrkDccDriver
//
class TCapsTrkDccDriver
{
public:
	TVersion	iVersion;
};




//
// class RTrkDccDriver
//
class RTrkDccDriver : public RBusLogicalChannel
{
public:

	enum TControl
	{
		EControlWrite = 0,
	};
	
	enum TRequest
	{
		ERequestRead=0x0, ERequestReadCancel=0x1,
		ERequestWrite=0x1,ERequestWriteCancel=0x2,
	};	
		
public:

	inline TInt Open();
	inline void Read(TRequestStatus &aStatus, TDes8 &aDes);
	inline void Read(TRequestStatus &aStatus, TDes8 &aDes, TInt aLength);
	inline void ReadOneOrMore(TRequestStatus &aStatus, TDes8 &aDes);
	inline void ReadCancel();
	inline void Write(TRequestStatus &aStatus, const TDesC8 &aDes);
	inline void Write(TRequestStatus &aStatus, const TDesC8 &aDes, TInt aLength);
	inline TInt Write(const TDesC8 &aDes);
	inline TInt Write(const TDesC8 &aDes, TInt aLength);
	inline void WriteCancel();

};


_LIT(KTrkDccDriverName,"TrkDcc Driver");

// Version information
const TInt KMajorDccVersionNumber=1;
const TInt KMinorDccVersionNumber=0;
const TInt KBuildDccVersionNumber=0;


inline TInt RTrkDccDriver::Open()
{
	#ifdef EKA2
	return DoCreate(KTrkDccDriverName, TVersion(KMajorDccVersionNumber, KMinorDccVersionNumber, KBuildDccVersionNumber), KNullUnit, NULL, NULL);
	#else
	return DoCreate(KTrkDccDriverName, TVersion(KMajorDccVersionNumber, KMinorDccVersionNumber, KBuildDccVersionNumber), NULL, KNullUnit, NULL, NULL);
	#endif
}

inline void RTrkDccDriver::Read(TRequestStatus &aStatus, TDes8 &aDes)
{
	TInt len = aDes.MaxLength();
	DoRequest(ERequestRead, aStatus, &aDes, &len);
}

inline void RTrkDccDriver::Read(TRequestStatus &aStatus, TDes8 &aDes, TInt aLength)
{
	DoRequest(ERequestRead, aStatus, &aDes, &aLength);
}

inline void RTrkDccDriver::ReadOneOrMore(TRequestStatus &aStatus, TDes8 &aDes)
{
	TInt len = (-aDes.MaxLength());
	DoRequest(ERequestRead, aStatus, &aDes, &len);
}

inline void RTrkDccDriver::ReadCancel()
{
	DoCancel(ERequestReadCancel);
}

inline void RTrkDccDriver::Write(TRequestStatus &aStatus, const TDesC8 &aDes)
{ 
	TInt len=aDes.Length();
	DoRequest(ERequestWrite, aStatus, (TAny *)&aDes, &len);
}

inline void RTrkDccDriver::Write(TRequestStatus &aStatus, const TDesC8 &aDes, TInt aLength)
{
	DoRequest(ERequestWrite, aStatus, (TAny *)&aDes, &aLength);
}

inline TInt RTrkDccDriver::Write(const TDesC8 &aDes)
{ 
	TInt len=aDes.Length();
	return DoControl(EControlWrite, reinterpret_cast<TAny*>(len), (TAny*)&aDes);
}

inline TInt RTrkDccDriver::Write(const TDesC8 &aDes, TInt aLength)
{
	return DoControl(EControlWrite, reinterpret_cast<TAny*>(aLength), (TAny*)&aDes);
}

inline void RTrkDccDriver::WriteCancel()
{
	DoCancel(ERequestWriteCancel);
}


#endif // __TRKDCCCOMM_H__
