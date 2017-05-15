/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2017, Rice University
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Rice University nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Zachary Kingston */

#ifndef OMPL_BASE_SPACES_NULLSPACE_STATE_SPACE_
#define OMPL_BASE_SPACES_NULLSPACE_STATE_SPACE_

#include "ompl/base/Constraint.h"
#include "ompl/base/spaces/ConstrainedStateSpace.h"

#include <eigen3/Eigen/Core>

namespace ompl
{
    namespace base
    {
        OMPL_CLASS_FORWARD(NullspaceStateSpace);

        class NullspaceStateSpace : public ConstrainedStateSpace
        {
        public:
            NullspaceStateSpace(const StateSpacePtr ambientSpace, const ConstraintPtr constraint)
              : ConstrainedStateSpace(ambientSpace, constraint)
              , epsilon_(0.2)
            {
            }

            virtual ~NullspaceStateSpace() = default;

            static void checkSpace(const SpaceInformation *si);

            bool traverseManifold(const State *from, const State *to, bool interpolate = false,
                                  std::vector<State*> *stateList = nullptr) const;

            virtual State *piecewiseInterpolate(const std::vector<State *> &stateList, const double t) const;

        private:
            const double epsilon_;
        };
    }
}

#endif
