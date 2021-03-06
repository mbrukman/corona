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

#ifndef __ratatouille__Rtt_TextureResourceCanvasAdapter__
#define __ratatouille__Rtt_TextureResourceCanvasAdapter__

#include "Rtt_TextureResourceAdapter.h"

namespace Rtt
{
		
class TextureResourceCanvasAdapter : public TextureResourceAdapter
{
	public:
		typedef TextureResourceCanvasAdapter Self;
		typedef TextureResourceAdapter Super;
		
	public:
		static const TextureResourceCanvasAdapter& Constant();
		
	protected:
		TextureResourceCanvasAdapter(){};
		
	public:
		virtual int ValueForKey(
								const LuaUserdataProxy& sender,
								lua_State *L,
								const char *key ) const override;

		virtual bool SetValueForKey(LuaUserdataProxy& sender,
									lua_State *L,
									const char *key,
									int valueIndex ) const override;

		virtual StringHash *GetHash( lua_State *L ) const override;
		
	private:
		static int setBackground( lua_State *L );
		static int draw( lua_State *L );
		static int invalidate( lua_State *L );

};
	
} // namespace Rtt


#endif /* defined(__ratatouille__Rtt_TextureResourceCanvasAdapter__) */
