/*
* Copyright (C) 2020 Centre National d'Etudes Spatiales (CNES)
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/
/************************************************************************************************************ 
 *                                                                                                          *
 *                                ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo         *
 *                             o                                                                            *
 *                          o                                                                               *
 *                        o                                                                                 *
 *                      o                                                                                   *
 *                     o       ooooooo       ooooooo    o         o      oo                                 *
 *    o              o       o        o     o       o   o         o     o   o                               *
 *      o           o       o          o   o         o  o         o    o      o                             *
 *        o        o       o           o   o         o  o         o    o        o                           *
 *         o      o        o      oooo     o         o  o         o   o           o                         *
 *          o    o          o              o         o  o         o   o           o                         *
 *           o  o            o             o         o  o o      o   o          o                           *
 *            oo              oooooooo    o         o   o  oooooo   o      oooo                             *
 *                                                     o                                                    *
 *                                                     o                                                    *
 *                                                    o                            o                        *
 *                                                    o            o      oooo     o   o      oooo          *
 *                                                   o             o         o    o    o         o          *
 *                                                   o            o       ooo     o   o       ooo           *
 *                                                               o       o       o   o          o           *
 *                                                               ooooo   oooo    o   ooooo  oooo            *
 *                                                                              o                           *
 *                                                                                                          *
 ************************************************************************************************************
 * HISTORIQUE                                                                                               *
 *                                                                                                          *
 * MOD : VERSION : 1-0-0  : 27 oct. 2011 : Creation                                                           
 *                                                                                                          *
 * FIN-HISTORIQUE                                                                                           *
 *                                                                                                          *
 * $Id$
 *                                                                                                          *
 ************************************************************************************************************/
#include "vnsMultiTemporalAOTMethodFunctions.h"
#include "otbImage.h"

#include "otbVectorImage.h"
#include "vnsUtilities.h"


int vnsMultiTemporalAOTMethodFunctionsNew(int /*argc*/, char * /*argv*/ [])
{
    const unsigned int Dimension = 2;
    /** Pixel typedefs */
    typedef float ImagePixelType;
    typedef unsigned char MaskPixelType;
    typedef short DatePixelType;

    /** Image typedefs */
    typedef otb::VectorImage<ImagePixelType, Dimension>     InputImageType;
    typedef otb::VectorImage<MaskPixelType, Dimension>      InputVectorMaskType;

    typedef otb::Image<DatePixelType, Dimension>            InputDateType;
    typedef otb::Image<MaskPixelType, Dimension>            InputMaskType;

    typedef vns::MultiTemporalAOTMethodFunctions<InputImageType,InputMaskType,InputVectorMaskType,InputDateType> FilterType;

    /** instantiating the filter */
    FilterType::Pointer filter = FilterType::New();
    FilterType::DateListType l_ListeDate;

    vns::Utilities::PrintList("l_ListeDate", l_ListeDate, std::cout);

    // 6617 6617 6617 6617 6585 6585 6617 6617 6617 6617 6617 6585 6585 6617 6617 6617 6617 6617 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585 6585
    // Code ancien  => 6585
    // Code nouveau => 6617
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6617);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);
    l_ListeDate.push_back(6585);

    FilterType::DateListType l_ListeDatetmpo = l_ListeDate;
    vns::Utilities::PrintList("l_ListeDatetmpo raw", l_ListeDatetmpo, std::cout);
    l_ListeDatetmpo.sort();
    vns::Utilities::PrintList("l_ListeDatetmpo sort", l_ListeDatetmpo, std::cout);
    l_ListeDatetmpo.reverse();
    vns::Utilities::PrintList("l_ListeDatetmpo reverse", l_ListeDatetmpo, std::cout);

    unsigned int lF = FilterType::ComputeGreaterFrequencyDate(l_ListeDate);
    std::cout <<"lF = "<<lF<<std::endl;
    if( lF != 6585 )
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
