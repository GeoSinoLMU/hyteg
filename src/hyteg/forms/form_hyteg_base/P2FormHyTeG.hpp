/*
 * Copyright (c) 2017-2020 Marcus Mohr.
 *
 * This file is part of HyTeG
 * (see https://i10git.cs.fau.de/hyteg/hyteg).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "hyteg/geometry/GeometryMap.hpp"
#include "hyteg/types/matrix.hpp"
#include "hyteg/types/pointnd.hpp"
#include "hyteg/forms/P2Form.hpp"

namespace hyteg {

class P2FormHyTeG : public P2Form
{
 public:

   virtual ~P2FormHyTeG() {}

   virtual void integrateAll( const std::array< Point3D, 3 >& coords, Matrix6r& elMat ) const = 0;

   virtual void integrateAll( const std::array< Point3D, 4 >& coords, Matrix10r& elMat ) const = 0;

   virtual bool assemble2D() const { return true; };

   virtual bool assemble3D() const { return false; };

   virtual bool assembly2DDefined() const { return true; };

   virtual bool assembly3DDefined() const { return false; };
};

} // namespace hyteg
