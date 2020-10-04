/**
 * @file hmtimer.hpp
 *
 * Timer utility routines and classes header file
 *
 * @if NOTICE
 *
 * $Id: hmtimer.hpp,v 1.21 2009/03/31 01:44:42 henrik Exp $
 *
 * Copyright (c) 2002-2009 proconX Pty Ltd. All rights reserved. 
 *
 * THIS IS PROPRIETARY SOFTWARE AND YOU NEED A LICENSE TO USE OR REDISTRIBUTE.
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


#ifndef _HMTIMER_H_INCLUDED
#define _HMTIMER_H_INCLUDED

#ifndef __cplusplus
#  error Must use C++ to compile this module!
#endif

// HM platform detection
#include "hmplatf.h"

#if defined(__WIN32__)
#  include <windows.h>
#elif defined(__VXWORKS__)
#  include <timers.h> // timerLib and clockLib
#  include <selectLib.h> // selectLib
#elif defined(__UNIX__)
#  include <unistd.h>
#  include <time.h>
// Include all headers where a timeval could hide:
#  include <sys/time.h>
#  include <sys/select.h>
#else
#  error "Platform not yet supported. Please add a new condition to this #if block or update hmplatf.h"
#endif


/*****************************************************************************
 * Timer interface
 *****************************************************************************/

/**
 * Timer class. This class implements a platform independent access
 * to timers.
 */
class HmTimer
{
  public:

   static void sleepMillis(unsigned long msTime);

   HmTimer();

   HmTimer(unsigned long msTime);

   int isExpired();

   void startMillis(unsigned long msTime);

   void sleepUntilExpiry();

   unsigned long left();

   unsigned long over();

#if defined(__UNIX__)
   void remain(timeval *remainTime); // Used for select on some platforms
#endif

  protected:

#if defined(__WIN32__)
     DWORD startTicks;
     DWORD timerTicks;
#else
#  if (defined(_POSIX_TIMERS) && !defined(__LINUX__) && !defined(__CYGWIN__) && !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)) || defined(__VXWORKS__)
   struct timespec expireTime;
#  elif defined(__UNIX__)
   struct timeval expireTime;
#  endif
#endif

  private:

   // Disable default operator and copy constructor
   HmTimer &operator=(HmTimer &);
   HmTimer(const HmTimer &);

};


#endif // ifdef ..._H_INCLUDED
