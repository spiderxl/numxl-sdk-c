/**
*  \addtogroup SFLUC 
*  @{
*  \file SFLUC.h
* 
*  \copyright (c) 2007-2014 Spider Financial Corp.
*  All rights reserved.
*  \brief  header file for the public API of SFLUC library 
*  \details  License system support for NumXL SDK
*  \copyright (c) 2007-2014 Spider Financial Corp.
*             All rights reserved.
*  \author Spider Financial Corp
*  \version 1.62
*  $Revision: 12362 $
*  $Date: 2012-10-26 18:12:09 -0500 (Fri, 26 Oct 2012) $
*/
#pragma once

// Functions API
extern "C"
{
  /// \name Initialzation APIs
  /// @{
  /*! 
  *   \brief initialize the SFLUC Library
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_Shutdown()
  */
  int   __stdcall SFLUC_Init( LPCSTR szAppName,             ///<  [in] application name (user-defined), but must match the configuration base filename
                              LPCSTR szLogDir,              ///<  [in, optional] absolute path of the log file directory. If NULL, LUC uses the default temp directory in the current user's profile
                              BOOL bEnableGracePeriod       ///<  [in] allow program to run for 7 days in the case the license key is missing
                              );                            

  /*! 
  *   \brief shutdown and release all resources used by SFLUC DLL
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_Init()
  */
  int   __stdcall SFLUC_Shutdown(void);                                                   
  /// \example luc_init.cpp

  /// @}


  /*! 
  *   \brief Examine the license key and activation code in the current system
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_Init()
  */
  int   __stdcall SFLUC_CHECK_LICENSE(void);


  /*! 
  *   \brief Query and retrieve the license level of the active license key
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_LICENSE_LEVEL()
  */
  int   __stdcall SFLUC_LICENSE_LEVEL(int* level /*! [out] license level (1=limited, 2=Pro) */);

  /*! 
  *   \brief Query and retrieve the unique identifier of the local machine
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_CHECK_LICENSE()
  */
  int   __stdcall SFLUC_MACHINEID(  LPSTR szBuffer,   ///< [out]  Machine or Host Id
                                    size_t* nLen      ///< [inout] maximum number of characters to copy to the buffer. 
                                    );

  /*! 
  *   \brief Query and retrieve the current license key
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_LICENSE_KEY(),SFLUC_ACTIVATION_CODE()
  */
  int   __stdcall SFLUC_LICENSE_KEY(LPSTR szBuffer,     ///< [out]  The buffer that will receive the License key
                                    size_t* nLen        ///< [inout] maximum number of characters to copy to the buffer.
                                    );

  /*! 
  *   \brief Query and retrieve the expiration date of the curent license key
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_ACTIVATION_CODE()
  */
  int   __stdcall SFLUC_LICENSE_KEY_EXPIRY(unsigned long* expiry /*! [out] expiration date expressed as number of days since January 1st, 1970 */);

  /*! 
  *   \brief Query and retrieve the activation code of the curent license key
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Error code
  *   \sa SFMacros.h, SFLUC_Init()
  */
  int   __stdcall SFLUC_ACTIVATION_CODE(LPSTR szCode,   ///< [out]  The buffer that will receive the activation code
                                        size_t* nLen    ///< [inout] maximum number of characters to copy to the buffer (minimum 32-character).
                                        );
  /*! 
  *   \brief Query and retrieve the activation status of curent license key
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Warning or Error code
  *   \sa SFMacros.h, SFLUC_LICENSE_STATUS(),SFLUC_LICENSE_KEY()
  */
  int   __stdcall SFLUC_LICENSE_STATUS(void);

  /*! 
  *   \brief Query and retrieve the expiration date of a given license key and activation code
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Warning or Error code
  *   \sa SFMacros.h, SFLUC_CHECK_KEYCODE()
  */
  int   __stdcall SFLUC_LICENSE_EXPIRY( LPCSTR szKey,               ///< [in] License key
                                        LPCSTR szActivationCode,    ///< [in] Activation code
                                        unsigned long* expiry       ///< [out] expiration date expressed as number of days since January 1st, 1970 
                                        );

  /*! 
  *   \brief Query and retrieve the expiration date and license level of a license key and activation code
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Warning or Error code
  *   \sa SFMacros.h, SFLUC_LICENSE_EXPIRY(), SFLUC_LICENSE_LEVEL()
  */
  int   __stdcall SFLUC_CHECK_KEYCODE(LPCSTR PDKey,                 ///< [in] Product key (i.e. 31223-200-162)
                                      LPCSTR szKey,                 ///< [in] License key
                                      LPCSTR szActCode,             ///< [in] Activation code
                                      ULONG* ulExpiry,              ///< [out] expiration date expressed as number of days since January 1st, 1970
                                      int* nLevel                   ///< [out] Effective license level: 1=Limited, 2=Full/Pro
                                      );



  /*! 
  *   \brief Query and retrieve the latest version available
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Warning or Error code
  *   \sa SFMacros.h, SFLUC_SERVICEDATE()
  */
  int  __stdcall SFLUC_UPDATEVERSION(LPCSTR szLicenseKey,           ///< [in] License key
                                      LPCSTR szFileVersion,         ///< [in] is the long file version (1.XX.XXXX.X)
                                      LPSTR updateVersion,          ///< [out] is the available most recent version available
                                      size_t* pVerSize,             ///< [inout] is the original size of the output buffer
                                      LPSTR downloadURL,            ///< [out] is the download URL version
                                      size_t* pURLSize              ///< [inout] is the size of "downloadURL" buffer
                                      );

  /*! 
  *   \brief Query and retrieve the service date for a given license
  *   \return status code of the operation
  *   \retval NDK_SUCCESS Operation successful
  *   \retval Warning or Error code
  *   \sa SFLUC_UPDATEVERSION(), SFLUC_LICENSE_LEVEL()
  */
  int  __stdcall SFLUC_SERVICEDATE(LPCSTR szLicenseKey,             ///< [in] is the license key
                                   LPLONG serviceDate               ///< [out] is the serial date number of the service/support expiry date
                                   );

}
/// @}