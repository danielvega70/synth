FmSynthAudioProcessor::FmSynthAudioProcessor()
    : apvts(*this, nullptr, "PARAMETERS", createParameterLayout()),
      editor(*this)
{
    setSize(640, 480);
}
