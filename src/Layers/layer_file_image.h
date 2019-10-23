#pragma once
#include "Layers\layer_file.h"
#include "Utils/LayerUtils.h"

class Layer_file_image : public Layer_file
{
public:
    Layer_file_image(string name, int instance, Layer_Manager * _layer_manager) : Layer_file(name, instance, _layer_manager) {};

    virtual const string get_display_name() const override { return "Image"; }
    virtual void handle_file(const string & _path) override;

protected:

    virtual void onDraw() const override;
    virtual void onReset() override;

    
    virtual float getFileWidth()  const { return img.getWidth(); };
    virtual float getFileHeight() const { return img.getHeight(); };

    virtual const vector<string> & get_allowed_exts() { return LayerUtils::img_exts; }

    ofImage img;

};

