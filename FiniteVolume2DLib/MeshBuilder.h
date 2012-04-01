/*
 * Name  : MeshBuilder
 * Path  : IMeshBuilder
 * Use   : Builds a mesh
 * Author: Sven Schmidt
 * Date  : 03/03/2012
 */
#pragma once

#include "DeclSpec.h"

#include "IMeshBuilder.h"
#include "Mesh.h"
#include "EntityCreatorManager.h"


#pragma warning(disable:4251)


class DECL_SYMBOLS MeshBuilder : public IMeshBuilder {
public:
    typedef std::shared_ptr<MeshBuilder> Ptr;

public:
    MeshBuilder(EntityCreatorManager::Ptr & entity_mgr);

    // FROM IMeshBuilder
    bool buildVertex(IGeometricEntity::Id_t mesh_id, bool on_boundary, double x, double y);
    bool buildFace(IGeometricEntity::Id_t mesh_id, bool on_boundary, std::vector<IGeometricEntity::Id_t> const & vertex_ids);
    bool buildCell(IGeometricEntity::Id_t mesh_id, std::vector<IGeometricEntity::Id_t> const & face_ids);

    boost::optional<Mesh::Ptr> getMesh() const;

private:
    Mesh::Ptr mesh_;

    EntityCreatorManager::Ptr entity_mgr_;
};

#pragma warning(default:4251)