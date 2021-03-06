//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "BaseMutex.h"
#include <mutex>


namespace Pthreads {

/// <summary>Recursive mutex used to synchronize access between threads.</summary>
/// <remarks>
///  Supports having the lock() function being called multiple times on the same thread without having to unlock it.
///  A recursive mutex counts the number of times it has been locked and it must be unlocked the same number of times
///  in order to release it and make it available to other threads.
/// </remarks>
class RecursiveMutex : public BaseMutex
{
	public:
		/// <summary>Creates a new recursive mutex.</summary>
		RecursiveMutex();

		/// <summary>Destroys resources taken by this mutex.</summary>
		virtual ~RecursiveMutex();

		/// <summary>
		///  Locks the mutex for the current thread. Will block the current thread if this mutex is currently locked
		///  by another thread and will not resume until its been unlocked.
		/// </summary>
		virtual void Lock();

		/// <summary>Unlocks the mutex, making it available to other threads.</summary>
		virtual void Unlock();

	private:
		std::recursive_mutex fMutex;
};

}	// namespace Pthreads
