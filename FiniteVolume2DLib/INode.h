/*
 * Name  : INode
 * Path  : IGeometricEntity
 * Use   : 
 * Author: Sven Schmidt
 * Date  : 04/07/2012
 */
#pragma once

#include "IGeometricEntity.h"

#include "Vector.h"


class INode : public IGeometricEntity {
public:
    virtual ~INode() {}

    virtual IGeometricEntity::Entity_t getEntityType() const = 0;
    virtual double                     x() const = 0;
    virtual double                     y() const = 0;
    virtual Vector                     vector() const = 0;
};