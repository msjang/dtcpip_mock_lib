// COPYRIGHT_BEGIN
//  DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
//
//  Copyright (C) 2008-2011, Cable Television Laboratories, Inc.
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, version 2. This program is distributed
//  in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
//  even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE. See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program.  If not, see  <http://www.gnu.org/licenses/>.
//
//  Please contact CableLabs if you need additional information or
//  have any questions.
//
//      CableLabs
//      858 Coal Creek Cir
//      Louisville, CO 80027-9750
//      303 661-9100
//      oc-mail@cablelabs.com
//
//  If you or the company you represent has a separate agreement with CableLabs
//  concerning the use of this code, your rights and obligations with respect
//  to this code shall be as set forth therein. No license is granted hereunder
//  for any other purpose.
// COPYRIGHT_END


#ifndef __H_MOCKDLL
#define __H_MOCKDLL

#define MPE_SUCCESS         0


int dtcpip_cmn_init(const char* storage_path);
void dtcpip_cmn_get_version(char* string, size_t length);

int dtcpip_src_init(unsigned short dtcp_port);
int dtcpip_src_open(int* session_handle, int is_audio_only);
int dtcpip_src_alloc_encrypt(int session_handle, unsigned char cci,
                 char* cleartext_data, size_t cleartext_size,
                 char** encrypted_data, size_t* encrypted_size);
int dtcpip_src_free(char* encrypted_data);
int dtcpip_src_close(int session_handle);

int dtcpip_snk_init(void);
int dtcpip_snk_open(char* ip_addr, unsigned short ip_port, int *session_handle);
int dtcpip_snk_alloc_decrypt(int session_handle, char* encrypted_data, size_t encrypted_size,
                 char** cleartext_data, size_t* cleartext_size);
int dtcpip_snk_free(char* cleartext_data);
int dtcpip_snk_close(int session_handle);


#endif