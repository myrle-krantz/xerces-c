/*
 * The Apache Software License, Version 1.1
 * 
 * Copyright (c) 1999 The Apache Software Foundation.  All rights 
 * reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 * 
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:  
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 * 
 * 4. The names "Xerces" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written 
 *    permission, please contact apache\@apache.org.
 * 
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 * 
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation, and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com .  For more information
 * on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */

/**
 * $Log$
 * Revision 1.2  2000/01/12 00:15:39  roddey
 * Changes to deal with multiply nested, relative pathed, entities and to deal
 * with the new URL class changes.
 *
 * Revision 1.1.1.1  1999/11/09 01:07:45  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:45:01  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */


// ---------------------------------------------------------------------------
//  Includes
// ---------------------------------------------------------------------------
#include    <util/XMLString.hpp>
#include    <sax/InputSource.hpp>



// ---------------------------------------------------------------------------
//  InputSource: Destructor
// ---------------------------------------------------------------------------
InputSource::~InputSource()
{
    delete [] fEncoding;
    delete [] fPublicId;
    delete [] fSystemId;
}


// ---------------------------------------------------------------------------
//  InputSource: Setter methods
// ---------------------------------------------------------------------------
void InputSource::setEncoding(const XMLCh* const encodingStr)
{
    delete [] fEncoding;
    fEncoding = XMLString::replicate(encodingStr);
}


void InputSource::setPublicId(const XMLCh* const publicId)
{
    delete [] fPublicId;
    fPublicId = XMLString::replicate(publicId);
}


void InputSource::setSystemId(const XMLCh* const systemId)
{
    delete [] fSystemId;
    fSystemId = XMLString::replicate(systemId);
}



// ---------------------------------------------------------------------------
//  InputSource: Hidden Constructors
// ---------------------------------------------------------------------------
InputSource::InputSource() :

    fEncoding(0)
    , fPublicId(0)
    , fSystemId(0)
{
}

InputSource::InputSource(const XMLCh* const systemId) :

    fEncoding(0)
    , fPublicId(0)
    , fSystemId(XMLString::replicate(systemId))
{
}

InputSource::InputSource(const  XMLCh* const systemId
                        , const XMLCh* const publicId) :

    fEncoding(0)
    , fPublicId(XMLString::replicate(publicId))
    , fSystemId(XMLString::replicate(systemId))
{
}

InputSource::InputSource(const char* const systemId) :

    fEncoding(0)
    , fPublicId(0)
    , fSystemId(XMLString::transcode(systemId))
{
}

InputSource::InputSource(const  char* const systemId
                        , const char* const publicId) :

    fEncoding(0)
    , fPublicId(XMLString::transcode(publicId))
    , fSystemId(XMLString::transcode(systemId))
{
}
