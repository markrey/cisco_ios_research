/* $Id: exec_show_dialer.h,v 3.3.20.2 1996/08/12 16:09:39 widmer Exp $
 * $Source: /release/112/cvs/Xsys/wan/exec_show_dialer.h,v $
 *------------------------------------------------------------------
 * E X E C _ S H O W _ D I A L E R . H
 *
 * Copyright (c) 1992-1996 by cisco Systems, Inc.
 * All Rights Reserved
 *------------------------------------------------------------------
 * $Log: exec_show_dialer.h,v $
 * Revision 3.3.20.2  1996/08/12  16:09:39  widmer
 * CSCdi65725:  Create Eolns macro that defaults csb->which to 0
 * Branch: California_branch
 * Add Eolns and Nvgenns macro that default csb->which to 0
 * Remove hidden keyword help strings
 *
 * Revision 3.3.20.1  1996/05/21  10:09:30  thille
 * CSCdi51599:  multiple /interface/ literals bloat code.
 * Branch: California_branch
 * Save another 392 bytes by doing away with duplicate literals.
 *
 * Revision 3.3  1996/01/29  07:10:17  hampton
 * Remove command number arguments passed to parse routines that only
 * perform a single function.  [CSCdi47717]
 *
 * Revision 3.2  1995/11/17  18:02:01  hampton
 * Remove old entries from the RCS header logs.
 *
 * Revision 3.1  1995/11/09  13:48:50  shaker
 * Bump version numbers from 2.x to 3.x.
 *
 * Revision 2.1  1995/07/02  01:46:08  tli
 * CSCdi36508:  Rationalize parser file placement, part I
 * Rationalize xns, atalk, vines, decnet, xremote, x25, unix, wan, tn3270,
 * clns, cdp
 *
 * Revision 2.1  1995/06/07  22:23:35  hampton
 * Bump version numbers from 1.x to 2.x.
 *
 *------------------------------------------------------------------
 * $Endlog$
 */


/******************************************************************
 * show dialer [interface <interface>]
 * 
 * OBJ(idb,1) = <interface>
 *
 * The 'interface' keyword is not necessary.  The action routine
 * doesn't use it, but we must parse it for compatability.
 */

EOLS	(show_dialer_eol, show_dialer,SHOW_DIALER);

INTERFACE_KEYWORD(show_dialer_if, show_dialer_eol, show_dialer_eol,
		  OBJ(idb,1), 
		  IFTYPE_SERIAL|IFTYPE_ASYNC|IFTYPE_BRI|IFTYPE_DIALER,
		  common_str_interface, "Show dialer information on one interface");


EOLS	(show_dialer_map_eol, show_dialer,SHOW_DIALER_MAP);
KEYWORD (show_dialer_map,show_dialer_map_eol,show_dialer_if,
	 "maps","Show dialer maps",
	 PRIV_USER);

KEYWORD (show_dialer, show_dialer_map, ALTERNATE,
	 "dialer", "Dialer parameters and statistics",
	 PRIV_USER);

#undef	ALTERNATE
#define	ALTERNATE	show_dialer
