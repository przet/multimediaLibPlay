#include <Windows.h>
#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>

#include <stdexcept>
#include <iostream>
int main()
{
    try
    {
        auto root = new osg::Group();
        auto cube = new osg::Box(osg::Vec3(0, 0, 0), 1.0f);
        auto cubeDrawable = new osg::ShapeDrawable(cube);
        auto cubeGeode = new osg::Geode();
        cubeGeode->addDrawable(cubeDrawable);
        root->addChild(cubeGeode);

        root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);

        osgViewer::Viewer viewer;
        viewer.setSceneData(root);
        viewer.setCameraManipulator(new osgGA::TrackballManipulator());
        viewer.realize();

        while (!viewer.done())
            viewer.frame();

        return 0;
    }
    catch (...)
    {
        std::cout << "ehllo\n";

    }

}
