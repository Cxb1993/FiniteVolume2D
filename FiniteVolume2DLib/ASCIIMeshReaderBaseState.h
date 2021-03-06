/*
 * Name  : ASCIIMeshReaderBaseState
 * Path  : IMeshReaderState
 * Use   : Represents the base state. Expected to read vertex data.
 * Author: Sven Schmidt
 * Date  : 03/04/2012
 */
#pragma once

#include "IMeshReaderState.h"

class IMeshBuilder;


class ASCIIMeshReaderBaseState : public IMeshReaderState {
public:
    // FROM IMeshReaderState
    bool process(std::vector<std::string> const & tokens, int line);

    bool inNodeMode() const;
    bool inFaceMode() const;
    bool inCellMode() const;
    bool inBoundaryConditionModeMode() const;


    static Ptr create(IMeshBuilder & mesh_builder);

private:
    /* Private constructor: Object cannot be created via constructor AND
     * object cannot be inherited from!
     */
    ASCIIMeshReaderBaseState(IMeshBuilder & mesh_builder);

    // no implicit assignment operator due to reference (mesh_builder_)
    ASCIIMeshReaderBaseState & operator=(ASCIIMeshReaderBaseState const & in);

private:
    IMeshBuilder & mesh_builder_;
};
