/*
 * GPUImage-x
 *
 * Copyright (C) 2017 Yijin Wang, Yiqian Wang
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "CannyEdgeDetectionFilter.hpp"

NS_GI_BEGIN

REGISTER_FILTER_CLASS(CannyEdgeDetectionFilter)

DEFINE_FILTER_CREATE_METHOD(CannyEdgeDetectionFilter)

CannyEdgeDetectionFilter::CannyEdgeDetectionFilter()
:_grayscaleFilter(0)
,_blurFilter(0)
,_edgeDetectionFilter(0)
,_nonMaximumSuppressionFilter(0)
,_weakPixelInclusionFilter(0)
{
}

CannyEdgeDetectionFilter::~CannyEdgeDetectionFilter() {
    if (_grayscaleFilter) {
        _grayscaleFilter->release();
        _grayscaleFilter = 0;
    }
    if (_blurFilter) {
        _blurFilter->release();
        _blurFilter = 0;
    }
    if (_edgeDetectionFilter) {
        _edgeDetectionFilter->release();
        _edgeDetectionFilter = 0;
    }
    if (_nonMaximumSuppressionFilter) {
        _nonMaximumSuppressionFilter->release();
        _nonMaximumSuppressionFilter = 0;
    }
    if (_weakPixelInclusionFilter) {
        _weakPixelInclusionFilter->release();
        _weakPixelInclusionFilter = 0;
    }
}

bool CannyEdgeDetectionFilter::init() {
    if (!FilterGroup::init()) {
        return false;
    }
    
    // 1. convert image to luminance
    _grayscaleFilter = GrayscaleFilter::create();
    
    // 2. apply a varialbe Gaussian blur
    _blurFilter = SingleComponentGaussianBlurFilter::create();
    
    // 3. soble edge detection
    _edgeDetectionFilter = DirectionalSobelEdgeDetectionFilter::create();
    
    // 4. apply non-maximum suppression
    _nonMaximumSuppressionFilter = DirectionalNonMaximumSuppressionFilter::create();
    
    // 5. include weak pixels to complete edges
    _weakPixelInclusionFilter = WeakPixelInclusionFilter::create();
    
    _grayscaleFilter->addTarget(_blurFilter)->addTarget(_edgeDetectionFilter)->addTarget(_nonMaximumSuppressionFilter)->addTarget(_weakPixelInclusionFilter);
    addFilter(_grayscaleFilter);
    
    setTerminalFilter(_weakPixelInclusionFilter);

    return true;
}

/**
 Getters and setters for various filter props
 */
/*
int CannyEdgeDetectionFilter::getBlurRadiusInPixels() {
    return _blurFilter->getRadius();
}
void CannyEdgeDetectionFilter::setBlurRadiusInPixels(int newValue) {
    _blurFilter->setRadius(newValue);
}

float CannyEdgeDetectionFilter::getBlurTexelSpacingMultiplier() {
    return _edgeDetectionFilter->_texelSizeMultiplier
}
void CannyEdgeDetectionFilter::setBlurTexelSpacingMultiplier(float newValue);

float CannyEdgeDetectionFilter::getTexelWidth();
void CannyEdgeDetectionFilter::setTexelWidth(float newValue);

float CannyEdgeDetectionFilter::getTexelHeight();
void CannyEdgeDetectionFilter::setTexelHeight(float newValue);

float CannyEdgeDetectionFilter::getUpperThreshold();
void CannyEdgeDetectionFilter::setUpperThreshold(float newValue);

float CannyEdgeDetectionFilter::getLowerThreshold();
void CannyEdgeDetectionFilter::setLowerThreshold(float newValue);
*/

NS_GI_END
