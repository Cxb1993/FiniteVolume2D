#include "ASCIIMeshReaderTest.h"

#include "FiniteVolume2DLib/ASCIIMeshReader.h"

#include <boost/filesystem.hpp>

namespace FS = boost::filesystem;


// Static class data members
ASCIIMeshReaderTest::MockMeshBuilder ASCIIMeshReaderTest::mock_builder_;


void
ASCIIMeshReaderTest::setUp() {
    mesh_filename_ = "Data\\grid.mesh";

    initMesh();
}

void
ASCIIMeshReaderTest::tearDown() {
}

void
ASCIIMeshReaderTest::testMeshFileExists() {
    bool exists = FS::exists(mesh_filename_);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Mesh file not found!", true, exists);
}

void
ASCIIMeshReaderTest::testNumberOfVertices() {
    int expect = mock_builder_.vertices_.size();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong number of vertices", 6, expect);
}

void
ASCIIMeshReaderTest::testVertex1() {
//    MockMeshBuilder::VertexMap_t::mapped_type const & vertiex_ids = mock_builder_.vertices_[2];
    auto const & vertex_ids = mock_builder_.vertices_[2];

    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Wrong vertex x coordinate", 2.123432, vertex_ids.first, 1E-10);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Wrong vertex y coordinate", -0.3847, vertex_ids.second, 1E-10);
}

void
ASCIIMeshReaderTest::testVertex2() {
    //    MockMeshBuilder::VertexMap_t::mapped_type const & vertiex_ids = mock_builder_.vertices_[4];
    auto const & vertex_ids = mock_builder_.vertices_[5];

    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Wrong vertex x coordinate", 5.123432, vertex_ids.first, 1E-10);
    CPPUNIT_ASSERT_DOUBLES_EQUAL_MESSAGE("Wrong vertex y coordinate", -0.3847, vertex_ids.second, 1E-10);
}

void
ASCIIMeshReaderTest::testNumberOfFaces() {
    int expect = mock_builder_.faces_.size();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong number of faces", 4, expect);
}

void
ASCIIMeshReaderTest::testFace() {
    auto const & face_ids = mock_builder_.faces_[1];

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong number of vertices", static_cast<size_t>(3), face_ids.size());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong face vertex id", static_cast<IGeometricEntity::Id_t>(0), face_ids[0]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong face vertex id", static_cast<IGeometricEntity::Id_t>(2), face_ids[1]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong face vertex id", static_cast<IGeometricEntity::Id_t>(3), face_ids[2]);
}

void
ASCIIMeshReaderTest::testNumberOfCells() {
    int expect = mock_builder_.cells_.size();
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong number of cells", 1, expect);
}

void
ASCIIMeshReaderTest::testCell() {
    auto const & cell_ids = mock_builder_.cells_[0];

    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong number of faces", static_cast<size_t>(4), cell_ids.size());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong cell face id", static_cast<IGeometricEntity::Id_t>(0), cell_ids[0]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong cell face id", static_cast<IGeometricEntity::Id_t>(1), cell_ids[1]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong cell face id", static_cast<IGeometricEntity::Id_t>(2), cell_ids[2]);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Wrong cell face id", static_cast<IGeometricEntity::Id_t>(3), cell_ids[3]);
}

void
ASCIIMeshReaderTest::initMesh() {
    static bool init = false;
    if (!init)
    {
        init = true;
        ASCIIMeshReader reader(mesh_filename_, mock_builder_);
        CPPUNIT_ASSERT_MESSAGE("Failed to read mesh file!", reader.read());
    }
}
