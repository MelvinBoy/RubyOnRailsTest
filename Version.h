// <~> --------------------------------------------------------------------------------
//   Dell confidential, proprietary information covered under NDA/SLA agreements
//   (c) Copyright 2000-2020 Dell Inc. No source code distribution allowed without prior consent from Dell
// <~> --------------------------------------------------------------------------------

#ifndef __VERSION_H__
#define __VERSION_H__

//
// Version settings for the EC build
//

#define VERSION_NO_STR(s) VERSION_NO_STRX(s)
#define VERSION_NO_STRX(s) #s

// Version will default to 99.99.99 if not passed in to build 
// (See dellversion description in Readme.BuildInfo)
# define       VERSION_NO            VERSION_NO_STR(EC_VERSION_NO)

#endif // __VERSION_H__