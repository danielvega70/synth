class FmSynthAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    FmSynthAudioProcessorEditor(FmSynthAudioProcessor& processor);
    ~FmSynthAudioProcessorEditor();

    void paint(juce::Graphics& g) override;
    void resized() override;

private:
    FmSynthAudioProcessor& processor;

    juce::Slider operatorModulationIndexSlider;
    juce::Slider operatorModulationCarrierSlider;
    juce::Slider operatorModulationModulatorSlider;
    juce::Slider operatorModulationDepthSlider;
    juce::Slider operatorCarrierIndexSlider;
    juce::Slider operatorCarrierCarrierSlider;
    juce::Slider operatorCarrierModulatorSlider;
    juce::Slider operatorCarrierDepthSlider;
};
