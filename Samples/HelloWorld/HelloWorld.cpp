// HelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

#include "../../Include/DynamsoftCodeParser.h"
#include "../../Include/DynamsoftLicense.h"
#include "../../Include/DynamsoftCore.h"

using namespace std;
using namespace dynamsoft::dcp;
using namespace dynamsoft::license;

#if defined(_WIN64) || defined(_WIN32)
#ifdef _WIN64
#pragma comment(lib, "../../Lib/Windows/x64/DynamsoftLicensex64.lib")
#pragma comment(lib, "../../Lib/Windows/x64/DynamsoftCorex64.lib")
#pragma comment(lib, "../../Lib/Windows/x64/DynamsoftCodeParserx64.lib")
#else
#pragma comment(lib, "../../Lib/Windows/x86/DynamsoftLicensex86.lib")
#pragma comment(lib, "../../Lib/Windows/x86/DynamsoftCorex86.lib")
#pragma comment(lib, "../../Lib/Windows/x86/DynamsoftCodeParserx86.lib")
#endif
#endif


int main(int, char**) {
	int errorCode = 0;
	char errorBuf[512];
	CParsedResultItem* parseResult = NULL;

	// Initialize license.
	// You can request and extend a trial license from https://www.dynamsoft.com/customer/license/trialLicense?product=dcp&utm_source=samples&package=c_cpp 
	// The string 'DLS2eyJvcmdhbml6YXRpb25JRCI6IjIwMDAwMSJ9' here is a free public trial license. Note that network connection is required for this license to work.
	errorCode = CLicenseManager::InitLicense("DLS2eyJvcmdhbml6YXRpb25JRCI6IjIwMDAwMSJ9", errorBuf, 512);
	if (errorCode != EC_OK)
	{
		// Add your code for license error processing;
		cout << errorBuf << endl;
	}

	// Create an instance of Code Parser
	CCodeParser* dcp = new CCodeParser();


	// Input source code
	char code[1024];
	cout << "Input your source code:";
	cin.getline(code, 1024);

	// Parse the code
	CParsedResultItem* dcpResult = dcp->Parse((unsigned char*)code, strlen(code), "", &errorCode);
	if (dcpResult != NULL)
	{
		string codeType = dcpResult->GetCodeType();
		cout << "CodeType: " << codeType << endl;
		if (codeType == "MRTD_TD1_ID")
		{
			if (dcpResult->GetFieldValue("documentNumber") != NULL)
			{
				cout << "Value of document number: " << dcpResult->GetFieldValue("documentNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/mrtd.html#mrtd_td1_id-fields for more supported fields
		}
		if (codeType == "MRTD_TD2_ID")
		{
			if (dcpResult->GetFieldValue("documentNumber") != NULL)
			{
				cout << "Value of document number: " << dcpResult->GetFieldValue("documentNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/mrtd.html#mrtd_td2_id-fields for more supported fields
		}
		if (codeType == "MRTD_TD2_VISA")
		{
			if (dcpResult->GetFieldValue("documentNumber") != NULL)
			{
				cout << "Value of document number: " << dcpResult->GetFieldValue("documentNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/mrtd.html#mrtd_td2_visa-fields for more supported fields
		}
		if (codeType == "MRTD_TD3_PASSPORT")
		{
			if (dcpResult->GetFieldValue("passportNumber") != NULL)
			{
				cout << "Value of passport number: " << dcpResult->GetFieldValue("passportNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/mrtd.html#mrtd_td3_passport-fields for more supported fields
		}
		if (codeType == "MRTD_TD3_VISA")
		{
			if (dcpResult->GetFieldValue("documentNumber") != NULL)
			{
				cout << "Value of document number: " << dcpResult->GetFieldValue("documentNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/mrtd.html#mrtd_td3_visa-fields for more supported fields
		}
		if (codeType == "AAMVA_DL_ID")
		{
			if (dcpResult->GetFieldValue("licenseNumber") != NULL)
			{
				cout << "Value of license number: " << dcpResult->GetFieldValue("licenseNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/aamva-dl-id.html#aamva_dl_id-fields for more supported fields
		}
		if (codeType == "AAMVA_DL_ID_WITH_MAG_STRIPE")
		{
			if (dcpResult->GetFieldValue("DLorID_Number") != NULL)
			{
				cout << "Value of ID number: " << dcpResult->GetFieldValue("DLorID_Number") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/aamva-dl-id.html#aamva_dl_id_with_mag_stripe-fields for more supported fields
		}
		if (codeType == "SOUTH_AFRICA_DL")
		{
			if (dcpResult->GetFieldValue("idNumber") != NULL)
			{
				cout << "Value of ID number: " << dcpResult->GetFieldValue("idNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/za-dl.html#fields for more supported fields
		}
		if (codeType == "AADHAAR")
		{
			if (dcpResult->GetFieldValue("idNumber") != NULL)
			{
				cout << "Value of ID number: " << dcpResult->GetFieldValue("idNumber") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/aadhaar.html#fields for more supported fields
		}
		if (codeType == "VIN")
		{
			if (dcpResult->GetFieldValue("WMI") != NULL)
			{
				cout << "Value of WMI: " << dcpResult->GetFieldValue("WMI") << endl;
			}
			// Check out https://www.dynamsoft.com/code-parser/docs/core/code-types/vin.html#fields for more supported fields
		}
	}
	else if (errorCode != ErrorCode::EC_OK)
	{
		cout << DC_GetErrorString(errorCode) << endl;
	}
	else
	{
		cout << "No parsing result for the code." << endl;
	}

	// Free the memory allocated for results
	if (dcpResult != NULL)
		delete dcpResult;
	if (dcp != NULL)
		delete dcp;

	cout << "Press any key to quit..." << endl;
	cin.ignore();
	return 0;
}
