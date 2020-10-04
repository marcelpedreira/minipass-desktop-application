/**
 * @file tcpsimple.c
 *
 * Modbus/TCP master example using C only calls. This example is using the C
 * wrapper library to access the FieldTalk C++ class methods from plain C code.
 *
 * This method is useful if FieldTalk has to be integrated in legacy C code
 * which cannot be recompiled using a C++ compiler.
 *
 * @if NOTICE
 *
 * Copyright (c) proconX Pty Ltd. All rights reserved.
 *
 * The following source file constitutes example program code and is
 * intended merely to illustrate useful programming techniques.  The user
 * is responsible for applying the code correctly.
 *
 * THIS SOFTWARE IS PROVIDED BY PROCONX AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PROCONX OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @endif
 */


// Platform header
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(__WIN32__)
#  include <windows.h>
#else
#  include <unistd.h>
#endif

// Include FieldTalk C exports
#include "MbusMasterCexports.h"


/*****************************************************************************
 * Gobal data
 *****************************************************************************/

#if defined (_UNICODE)
TCHAR *hostName = L"10.0.0.11";
#else
char *hostName = "127.0.0.1";
#endif
MbusMasterProtocolHdl mbusProtocol;


/*****************************************************************************
 * Function implementation
 *****************************************************************************/

/**
 * Opens protocol
 */
void openProtocol(void)
{
   int result;

   mbusProtocol = mbusMaster_createTcpProtocol();
   result = mbusMaster_openTcpProtocol(mbusProtocol, hostName);
   if (result != FTALK_SUCCESS)
   {
      fprintf(stderr, "Error opening protocol: %s!\n",
                       mbusMaster_getErrorText(result));
      exit(EXIT_FAILURE);
   }
}


/**
 * Closes protocol
 */
void closeProtocol(void)
{
   mbusMaster_closeProtocol(mbusProtocol);
   mbusMaster_destroyProtocol(mbusProtocol);
}


/**
 * Cyclic loop which polls every one second 10 registers starting at
 * reference 100 from slave # 1
 */
void runPollLoop(void)
{
   short dataArr[10];

   for (;;)
   {
      int i;
      int result;

      result = mbusMaster_readMultipleRegisters(mbusProtocol,
                                                1, 100,
                                                dataArr,
                                                sizeof(dataArr) / 2);
      if (result == FTALK_SUCCESS)
         for (i = 0; i < (int) (sizeof(dataArr) / 2); i++)
            printf("[%d]: %hd\n", 100 + i, dataArr[i]);
      else
      {
         fprintf(stderr, "%s!\n", mbusMaster_getErrorText(result));
         // Stop for fatal errors
         if (!(result & FTALK_BUS_PROTOCOL_ERROR_CLASS))
            return;
      }

#if defined(_WIN32) || defined(__WIN32__)
      Sleep(1000);
#else
      sleep(1);
#endif
   }
}


/**
 * Main function.
 *
 * @return Error code: 0 = OK, else error
 */
#if defined(_WIN32_WCE)
int wmain()
#else
int main()
#endif
{
   openProtocol();

   runPollLoop();

   closeProtocol();
   return (EXIT_SUCCESS);
}
