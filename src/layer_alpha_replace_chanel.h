#pragma once
#include "layer_filter_alpha_replace.h"

class Layer_alpha_replace_channel : public  Layer_filter_alpha_replace
{
public:
    Layer_alpha_replace_channel(string name, Layer_Manager * _layer_manager)
        : Layer_filter_alpha_replace(name, _layer_manager) {};

protected:
    virtual void onDraw(const ofTexture & _baseTex) const override;
    virtual void onSetupParams() override;

    virtual void setupShader() override;
    virtual ofTexture & getAlphaTexture() const { return alphaBlur.getBackTexture(); }


    void update_alpha_texture(const ofTexture & _baseTex) const;

    ofParameter<glm::vec2> p_threshold;
    ofParameter<int>       p_blurPasses;
    ofParameter<bool>      p_invert;
    ofParameter<glm::vec4> p_color;
    
    mutable pingPongFbo    alphaBlur;
    shared_ptr<AutoShader> blur_shader;
    shared_ptr<AutoShader> threshold_shader;

private:
    ofEventListener l_onBlurShaderLoad;
    ofEventListener l_onTheshShaderLoad;
};

