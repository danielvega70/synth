class FmSynthAudioProcessor : public juce::AudioProcessor
{
public:
    FmSynthAudioProcessor();
    ~FmSynthAudioProcessor();

    void prepareToPlay(double sampleRate, int bufferSize) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;

    bool isVST3() const override { return true; } // Use VST3 plug-in format
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumParameters() override;
    float getParameter(int index) override;
    void setParameter(int index, float newValue) override;
    const juce::String getParameterName(int index) override;
    const juce::String getParameterText(int index) override;
    juce::String getParameterLabel(int index) const override;

    bool isParameterAutomatable(int index) const override;

    juce::AudioProcessorValueTreeState& getAPVTS() { return apvts; }

private:
    FmSynth synth; // Sintetizador FM
    juce::AudioProcessorValueTreeState apvts; // Estado de los parámetros del sintetizador
};
