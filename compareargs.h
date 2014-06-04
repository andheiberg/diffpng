/*
Compare Args
Copyright (C) 2006-2011 Yangli Hector Yee
Copyright (C) 2011-2014 Steven Myint

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef DIFFPNG_COMPARE_ARGS_H
#define DIFFPNG_COMPARE_ARGS_H

#include <memory>
#include <stdexcept>
#include <string>

class RGBAImage;

// Args to pass into the comparison function
class CompareArgs
{
public:
    CompareArgs();
    bool Parse_Args(int argc, char **argv);
    void Print_Args() const;

    std::shared_ptr<RGBAImage> ImgA;     // Image A
    std::shared_ptr<RGBAImage> ImgB;     // Image B
    std::unique_ptr<RGBAImage> ImgDiff;  // Diff image
    bool Verbose;                        // Print lots of text or not
    bool LuminanceOnly;  // Only consider luminance; ignore chroma channels in
                         // the
                         // comparison.
    bool SumErrors;  // Print a sum of the luminance and color differences of
                     // each
                     // pixel.
    float FieldOfView;  // Field of view in degrees
    float Gamma;        // The gamma to convert to linear color space
    float Luminance;    // the display's luminance
    unsigned int ThresholdPixels;  // How many pixels different to ignore
    std::string ErrorStr;          // Error string

    // How much color to use in the metric.
    // 0.0 is the same as LuminanceOnly = true,
    // 1.0 means full strength.
    float ColorFactor;

    // How much to down sample image before comparing, in powers of 2.
    unsigned int DownSample;
};


class ParseException : public virtual std::invalid_argument
{
public:

    ParseException(const std::string &message)
        : std::invalid_argument(message)
    {
    }
};

#endif