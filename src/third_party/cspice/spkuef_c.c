/*

-Procedure spkuef_c ( S/P Kernel, Unload ephemeris file )

-Abstract
 
   Unload an ephemeris file so that it will no longer be searched by 
   the readers. 

-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Required_Reading
 
   SPK 
 
-Keywords
 
   EPHEMERIS 
   FILES 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZst.h"


   void spkuef_c ( SpiceInt handle )

/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   handle     I   Handle of file to be unloaded 
 
-Detailed_Input
 
   handle     Integer handle assigned to the file upon loading. 
 
-Detailed_Output
 
   None. 
 
-Parameters
 
   None. 
 
-Exceptions
 
   None. 
 
-Files
 
   The file referred to by handle is unloaded. 
 
-Particulars

   A file is removed from consideration by the readers by a call to 
   spkuef_c. 
 
   The file table entry corresponding to the file referenced by 
   handle, is removed.  Also any segment table entry which came from 
   the specified file is also deleted. 
 
   If the file specified by handle does not appear in the file table, 
   nothing happens. 
 
-Examples
 
    
   // Unload the kernel file assigned to hand..
      spkuef_c ( hand1 );

   Also see the Example in spkbsr.for. 
 
-Restrictions
 
   None. 
 
-Literature_References
 
   NAIF Document 168.0, "S- and P- Kernel (SPK) Specification and 
   User's Guide" 
 
-Author_and_Institution

   J.M. Lynch      (JPL) 
   R.E. Thurman    (JPL) 
   I.M. Underwood  (JPL) 
 
-Version

   -CSPICE Version 1.0.1, 02-JUL-2003 (EDW)

       Corrected trivial typo in the Version 1.0.0 line.
       The typo caused an integrity check script to fail.

   -CSPICE Version 1.0.0, 19-OCT-1997 (EDW)

-Index_Entries
 
   unload spk ephemeris file
 
-&
*/

{ /* Begin spkuef_c */

   /*
   Participate in error handling
   */
   chkin_c( "spkuef_c");


   /*
   Call the f2c'd Fortran routine.
   */
   spkuef_ ( &handle );


   chkout_c( "spkuef_c");

} /* end spkuef_c */

