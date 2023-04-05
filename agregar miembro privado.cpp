class FmSynthAudioProcessor  : public juce::AudioProcessor
{
public:
    // ...

private:
    juce::AudioProcessorValueTreeState apvts;

    FmSynthAudioProcessorEditor editor;
};
