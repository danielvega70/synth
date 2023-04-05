FmSynthAudioProcessorEditor::FmSynthAudioProcessorEditor(FmSynthAudioProcessor& processor)
    : AudioProcessorEditor(&processor), processor(processor),
      operatorModulationIndexSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorModulationCarrierSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorModulationModulatorSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorModulationDepthSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorCarrierIndexSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorCarrierCarrierSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorCarrierModulatorSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox),
      operatorCarrierDepthSlider(juce::Slider::RotaryVerticalDrag, juce::Slider::NoTextBox)
{
    // Configurar los componentes gráficos de la interfaz de usuario
    addAndMakeVisible(operatorModulationIndexSlider);
    operatorModulationIndexSlider.setRange(0.0, 1.0, 0.01);
    operatorModulationIndexSlider.setValue(processor.getAPVTS().getRawParameterValue("operator_modulation_index")->load());
    operatorModulationIndexSlider.onValueChange = [this] { processor.getAPVTS().getParameter("operator_modulation_index")->setValueNotifyingHost((float)operatorModulationIndexSlider.getValue()); };
    operatorModulationIndexSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    operatorModulationIndexSlider.setLookAndFeel(&laFaderLookAndFeel);

    // Configurar los demás componentes gráficos de la interfaz de usuario de manera similar
    // ...

    setSize(640, 480);
}
