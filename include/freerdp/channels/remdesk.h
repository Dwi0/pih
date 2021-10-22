/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Remote Assistance Virtual Channel
 *
 * Copyright 2014 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_CHANNEL_REMDESK_H
#define FREERDP_CHANNEL_REMDESK_H

#include <freerdp/api.h>
#include <freerdp/types.h>

#define REMDESK_SVC_CHANNEL_NAME "remdesk"

#define REMDESK_ERROR_NOERROR 0
#define REMDESK_ERROR_NOINFO 1
#define REMDESK_ERROR_LOCALNOTERROR 3
#define REMDESK_ERROR_REMOTEBYUSER 4
#define REMDESK_ERROR_BYSERVER 5
#define REMDESK_ERROR_DNSLOOKUPFAILED 6
#define REMDESK_ERROR_OUTOFMEMORY 7
#define REMDESK_ERROR_CONNECTIONTIMEDOUT 8
#define REMDESK_ERROR_SOCKETCONNECTFAILED 9
#define REMDESK_ERROR_HOSTNOTFOUND 11
#define REMDESK_ERROR_WINSOCKSENDFAILED 12
#define REMDESK_ERROR_INVALIDIPADDR 14
#define REMDESK_ERROR_SOCKETRECVFAILED 15
#define REMDESK_ERROR_INVALIDENCRYPTION 18
#define REMDESK_ERROR_GETHOSTBYNAMEFAILED 20
#define REMDESK_ERROR_LICENSINGFAILED 21
#define REMDESK_ERROR_ENCRYPTIONERROR 22
#define REMDESK_ERROR_DECRYPTIONERROR 23
#define REMDESK_ERROR_INVALIDPARAMETERSTRING 24
#define REMDESK_ERROR_HELPSESSIONNOTFOUND 25
#define REMDESK_ERROR_INVALIDPASSWORD 26
#define REMDESK_ERROR_HELPSESSIONEXPIRED 27
#define REMDESK_ERROR_CANTOPENRESOLVER 28
#define REMDESK_ERROR_UNKNOWNSESSMGRERROR 29
#define REMDESK_ERROR_CANTFORMLINKTOUSERSESSION 30
#define REMDESK_ERROR_RCPROTOCOLERROR 32
#define REMDESK_ERROR_RCUNKNOWNERROR 33
#define REMDESK_ERROR_INTERNALERROR 34
#define REMDESK_ERROR_HELPEERESPONSEPENDING 35
#define REMDESK_ERROR_HELPEESAIDYES 36
#define REMDESK_ERROR_HELPEEALREADYBEINGHELPED 37
#define REMDESK_ERROR_HELPEECONSIDERINGHELP 38
#define REMDESK_ERROR_HELPEENEVERRESPONDED 40
#define REMDESK_ERROR_HELPEESAIDNO 41
#define REMDESK_ERROR_HELPSESSIONACCESSDENIED 42
#define REMDESK_ERROR_USERNOTFOUND 43
#define REMDESK_ERROR_SESSMGRERRORNOTINIT 44
#define REMDESK_ERROR_SELFHELPNOTSUPPORTED 45
#define REMDESK_ERROR_INCOMPATIBLEVERSION 47
#define REMDESK_ERROR_SESSIONNOTCONNECTED 48
#define REMDESK_ERROR_SYSTEMSHUTDOWN 50
#define REMDESK_ERROR_STOPLISTENBYUSER 51
#define REMDESK_ERROR_WINSOCK_FAILED 52
#define REMDESK_ERROR_MISMATCHPARMS 53
#define REMDESK_ERROR_PASSWORDS_DONT_MATCH 61
#define REMDESK_ERROR_SHADOWEND_BASE 300
#define REMDESK_ERROR_SHADOWEND_CONFIGCHANGE 301
#define REMDESK_ERROR_SHADOWEND_UNKNOWN 302

struct _REMDESK_CHANNEL_HEADER
{
	UINT32 DataLength;
	char ChannelName[32];
};
typedef struct _REMDESK_CHANNEL_HEADER REMDESK_CHANNEL_HEADER;

#define REMDESK_CHANNEL_CTL_NAME "RC_CTL"
#define REMDESK_CHANNEL_CTL_SIZE 22

struct _REMDESK_CTL_HEADER
{
	REMDESK_CHANNEL_HEADER ch;

	UINT32 msgType;
};
typedef struct _REMDESK_CTL_HEADER REMDESK_CTL_HEADER;

#define REMDESK_CTL_REMOTE_CONTROL_DESKTOP 1
#define REMDESK_CTL_RESULT 2
#define REMDESK_CTL_AUTHENTICATE 3
#define REMDESK_CTL_SERVER_ANNOUNCE 4
#define REMDESK_CTL_DISCONNECT 5
#define REMDESK_CTL_VERSIONINFO 6
#define REMDESK_CTL_ISCONNECTED 7
#define REMDESK_CTL_VERIFY_PASSWORD 8
#define REMDESK_CTL_EXPERT_ON_VISTA 9
#define REMDESK_CTL_RANOVICE_NAME 10
#define REMDESK_CTL_RAEXPERT_NAME 11
#define REMDESK_CTL_TOKEN 12

struct _REMDESK_CTL_RESULT_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	UINT32 result;
};
typedef struct _REMDESK_CTL_RESULT_PDU REMDESK_CTL_RESULT_PDU;

struct _REMDESK_CTL_VERSION_INFO_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	UINT32 versionMajor;
	UINT32 versionMinor;
};
typedef struct _REMDESK_CTL_VERSION_INFO_PDU REMDESK_CTL_VERSION_INFO_PDU;

struct _REMDESK_CTL_AUTHENTICATE_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	char* raConnectionString;
	char* expertBlob;
};
typedef struct _REMDESK_CTL_AUTHENTICATE_PDU REMDESK_CTL_AUTHENTICATE_PDU;

struct _REMDESK_CTL_REMOTE_CONTROL_DESKTOP_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	char* raConnectionString;
};
typedef struct _REMDESK_CTL_REMOTE_CONTROL_DESKTOP_PDU REMDESK_CTL_REMOTE_CONTROL_DESKTOP_PDU;

struct _REMDESK_CTL_VERIFY_PASSWORD_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	char* expertBlob;
};
typedef struct _REMDESK_CTL_VERIFY_PASSWORD_PDU REMDESK_CTL_VERIFY_PASSWORD_PDU;

struct _REMDESK_CTL_EXPERT_ON_VISTA_PDU
{
	REMDESK_CTL_HEADER ctlHeader;

	BYTE* EncryptedPassword;
	UINT32 EncryptedPasswordLength;
};
typedef struct _REMDESK_CTL_EXPERT_ON_VISTA_PDU REMDESK_CTL_EXPERT_ON_VISTA_PDU;

#endif /* FREERDP_CHANNEL_REMDESK_H */
