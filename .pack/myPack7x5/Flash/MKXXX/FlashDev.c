/* -----------------------------------------------------------------------------
 * Copyright (c) 2016 ARM Ltd.
 *
 * This software is provided 'as-is', without any express or implied warranty. 
 * In no event will the authors be held liable for any damages arising from 
 * the use of this software. Permission is granted to anyone to use this 
 * software for any purpose, including commercial applications, and to alter 
 * it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not 
 *    claim that you wrote the original software. If you use this software in
 *    a product, an acknowledgment in the product documentation would be 
 *    appreciated but is not required. 
 * 
 * 2. Altered source versions must be plainly marked as such, and must not be 
 *    misrepresented as being the original software. 
 * 
 * 3. This notice may not be removed or altered from any source distribution.
 *   
 *
 * $Date:        29. January 2016
 * $Revision:    V1.00
 *  
 * Project:      Flash Device Description for Freescale MKXX Flash
 * --------------------------------------------------------------------------- */

/* History:
 *  Version 1.00
 *    Initial release
 */ 

#include "..\FlashOS.H"        // FlashOS Structures

#ifdef MKP64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 64kB Prog Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00010000,                 // Device Size (64kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP64_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 50Mhz 64kB Prog Flash",// Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00010000,                   // Device Size (64kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP64_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL43_48MHZ)
   "MKL43 48Mhz 64kB Prog Flash",// Device Name 
#else
   "MKXX 48Mhz 64kB Prog Flash",// Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00010000,                   // Device Size (64kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP64_4KB_SECTOR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 64kB PFlash SEC(4KB)", // Device Name 
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00010000,                  // Device Size (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,          // Sector Size  4kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 128kB Prog Flash",    // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP128_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 50Mhz 128kB Prog Flash",// Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00020000,                   // Device Size (128kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP128_4KB_SECTOR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 128kB PFlash SEC(4KB)",// Device Name 
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00020000,                  // Device Size (128kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,          // Sector Size  4kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP256_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL43_48MHZ)
   "MKL43 48Mhz 256kB Prog Flash",// Device Name 
#else
   "MKXX 48Mhz 256kB Prog Flash",// Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00040000,                   // Device Size (256kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP128_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL43_48MHZ)
   "MKL43 48Mhz 128kB Prog Flash",// Device Name 
#else
   "MKXX 48Mhz 128kB Prog Flash",// Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00020000,                   // Device Size (128kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP160_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 48Mhz 160kB Prog Flash",// Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00028000,                   // Device Size (160kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (160 Sectors)
   SECTOR_END
};
#endif


#ifdef MKP32_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 50Mhz 32kB Prog Flash", // Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00008000,                   // Device Size (32kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP32_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL03_48MHZ)
   "MKL03 48Mhz 32kB Prog Flash",// Device Name 
#elif defined (MKL43_48MHZ)
   "MKL43 48Mhz 32kB Prog Flash",// Device Name 
#else
   "MKXX 48Mhz 32kB Prog Flash", // Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00008000,                   // Device Size (32kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP16_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL03_48MHZ)
   "MKL03 48Mhz 16kB Prog Flash",// Device Name 
#else
   "MKXX 48Mhz 16kB Prog Flash", // Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00004000,                   // Device Size (16kB)
   128,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP8_48MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
#if defined (MKL03_48MHZ)
   "MKL03 48Mhz 8kB Prog Flash", // Device Name 
#else
   "MKXX 48Mhz 8kB Prog Flash",  // Device Name 
#endif
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00002000,                   // Device Size (8kB)
   32,                           // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (8 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
#if defined (MKL28_72MHZ)
   "MKL28 256kB Prog Flash",   // Device Name 
#else
   "MKXX 256kB Prog Flash",    // Device Name 
#endif
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP256_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 50Mhz 256kB Prog Flash",// Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00040000,                   // Device Size (256kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,         // Sector Size  1kB (256 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP256_4KB_SECTOR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 256kB PFlash SEC(4KB)",// Device Name 
   ONCHIP,                      // Device Type
   0x00000000,                  // Device Start Address
   0x00040000,                  // Device Size (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,          // Sector Size  4kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
#if defined (MKL28_72MHZ)
   "MKL28 512kB Prog Flash",   // Device Name 
#else
   "MKxxN 512kB Prog Flash",   // Device Name 
#endif
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (256 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP512X
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKxxX 512kB Prog Flash",   // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP512_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 50Mhz 512kB Prog Flash",// Device Name 
   ONCHIP,                       // Device Type
   0x00000000,                   // Device Start Address
   0x00080000,                   // Device Size (512kB)
   256,                          // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000400, 0x000000,           // Sector Size  1kB (512 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP1024
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKxxN 1024KB Prog Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00100000,                 // Device Size (1MB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (256 Sectors)
   SECTOR_END
};
#endif

#ifdef MKP2048
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKxxN 2048KB Prog Flash",  // Device Name 
   ONCHIP,                     // Device Type
   0x00000000,                 // Device Start Address
   0x00200000,                 // Device Size (2MB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (512 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD32
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 32kB Data Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00008000,                 // Device Size (32kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (16 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD32_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 50Mhz 32kB Data Flash",// Device Name 
   ONCHIP,                      // Device Type
   0x10000000,                  // Device Start Address
   0x00008000,                  // Device Size (32kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000400, 0x000000,          // Sector Size  1kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD32_72MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 72Mhz 32kB Data Flash",// Device Name 
   ONCHIP,                      // Device Type
   0x10000000,                  // Device Start Address
   0x00008000,                  // Device Size (32kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000400, 0x000000,          // Sector Size  1kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD64
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 64kB Data Flash",     // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00010000,                 // Device Size (128kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD64_50MHZ
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 50Mhz 64kB Data Flash",// Device Name 
   ONCHIP,                      // Device Type
   0x10000000,                  // Device Start Address
   0x00010000,                  // Device Size (64kB)
   256,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000400, 0x000000,          // Sector Size  1kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD128
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 128kB Data Flash",    // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00020000,                 // Device Size (128kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (64 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD128_4KB_SECTOR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 128kB DFlash SEC(4KB)",// Device Name 
   ONCHIP,                      // Device Type
   0x10000000,                  // Device Start Address
   0x00020000,                  // Device Size (128kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,          // Sector Size  4kB (32 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD256_4KB_SECTOR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,              // Driver Version, do not modify!
   "MKXX 256kB DFlash SEC(4KB)",// Device Name 
   ONCHIP,                      // Device Type
   0x10000000,                  // Device Start Address
   0x00040000,                  // Device Size (256kB)
   512,                         // Programming Page Size
   0,                           // Reserved, must be 0
   0xFF,                        // Initial Content of Erased Memory
   1000,                        // Program Page Timeout 1000 mSec
   3000,                        // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,          // Sector Size  4kB (64 Sectors)
   SECTOR_END
};
#endif


#ifdef MKD256
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 256kB Data Flash",    // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00040000,                 // Device Size (256kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000800, 0x000000,         // Sector Size  2kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKD512
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 512kB Data Flash",    // Device Name 
   ONCHIP,                     // Device Type
   0x10000000,                 // Device Start Address
   0x00080000,                 // Device Size (512kB)
   512,                        // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x001000, 0x000000,         // Sector Size  4kB (128 Sectors)
   SECTOR_END
};
#endif

#ifdef MKPIFR //Program Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX Program Flash IFR",   // Device Name 
   ONCHIP,                     // Device Type
   0x0FFFFFC0,                 // Device Start Address
   0x00000040,                 // Device Size (64 Byte)
   64,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec

// Specify Size and Address of Sectors
   0x000040, 0x000000,         // Sector Size  64 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKPIFR_50MHZ  //Program Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 50Mhz Program Flash IFR",// Device Name 
   ONCHIP,                     // Device Type
   0x0FFFFFC0,                 // Device Start Address
   0x00000040,                 // Device Size (64 Byte)
   64,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000040, 0x000000,         // Sector Size  64 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKPIFR_48MHZ  //Program Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 48Mhz Program Flash IFR",// Device Name 
   ONCHIP,                     // Device Type
   0x0FFFFFC0,                 // Device Start Address
   0x00000040,                 // Device Size (64 Byte)
   64,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000040, 0x000000,         // Sector Size  64 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKPIFR_120MHZ  //Program Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 120Mhz Program Flash IFR",// Device Name 
   ONCHIP,                     // Device Type
   0x0FFFFFC0,                 // Device Start Address
   0x00000040,                 // Device Size (64 Byte)
   64,                         // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000040, 0x000000,         // Sector Size  64 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKDIFR //Data Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX Data Flash IFR",      // Device Name 
   ONCHIP,                     // Device Type
   0x13FFFFFC,                 // Device Start Address
   0x00000004,                 // Device Size (4 Byte)
   4,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000004, 0x000000,         // Sector Size  4 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKDIFR_50MHZ  //Data Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,             // Driver Version, do not modify!
   "MKXX 50Mhz Data Flash IFR",// Device Name 
   ONCHIP,                     // Device Type
   0x13FFFFFC,                 // Device Start Address
   0x00000004,                 // Device Size (4 Byte)
   4,                          // Programming Page Size
   0,                          // Reserved, must be 0
   0xFF,                       // Initial Content of Erased Memory
   1000,                       // Program Page Timeout 1000 mSec
   3000,                       // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000004, 0x000000,         // Sector Size  4 Byte (1 Sector)
   SECTOR_END
};
#endif

#ifdef MKDIFR_120MHZ  //Data Flash IFR
struct FlashDevice const FlashDevice  =  {
   FLASH_DRV_VERS,               // Driver Version, do not modify!
   "MKXX 120Mhz Data Flash IFR", // Device Name 
   ONCHIP,                       // Device Type
   0x13FFFFF8,                   // Device Start Address
   0x00000008,                   // Device Size (8 Byte)
   8,                            // Programming Page Size
   0,                            // Reserved, must be 0
   0xFF,                         // Initial Content of Erased Memory
   1000,                         // Program Page Timeout 1000 mSec
   3000,                         // Erase Sector Timeout 3000 mSec
// Specify Size and Address of Sectors
   0x000008, 0x000000,           // Sector Size  4 Byte (1 Sector)
   SECTOR_END
};
#endif
