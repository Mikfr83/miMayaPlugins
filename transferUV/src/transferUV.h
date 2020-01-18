// transferUV.h
//
// Copyright (c) 2018 Michitaka Inoue
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#ifndef __TRANSFERUV_H__
#define __TRANSFERUV_H__

#include <maya/MDagPath.h>
#include <maya/MFloatArray.h>
#include <maya/MFnMesh.h>
#include <maya/MIntArray.h>
#include <maya/MPxCommand.h>
#include <string>

class TransferUV : public MPxCommand {
public:
    TransferUV();
    virtual ~TransferUV();
    MStatus doIt(const MArgList& argList);
    MStatus undoIt();
    MStatus redoIt();
    bool isUndoable() const;
    static void* creator();
    static MSyntax newSyntax();

private:
    MDagPath sourceDagPath;
    MDagPath targetDagPath;

    MString sourceUvSet;
    MString targetUvSet;
    MString sourceMesh;
    MString targetMesh;

    // Orig infor for undo
    MIntArray originalUvCounts;
    MIntArray originalUvIds;
    MFloatArray originalUarray;
    MFloatArray originalVarray;
};

#endif /* defined(__TRANSFERUV_H__) */
