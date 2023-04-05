FmSynthAudioProcessor::FmSynthAudioProcessor()
    : apvts(*this, nullptr, "PARAMETERS", createParameterLayout()) // Configurar el árbol de valores
{
    // Establecer los valores predeterminados para los parámetros
    apvts.state.setProperty("operator_modulation_index", 0.5, nullptr);
    apvts.state.setProperty("operator_modulation_carrier", 440.0, nullptr);
    apvts.state.setProperty("operator_modulation_modulator", 220.0, nullptr);
    apvts.state.setProperty("operator_modulation_depth", 1.0, nullptr);
    apvts.state.setProperty("operator_carrier_index", 1.0, nullptr);
    apvts.state.setProperty("operator_carrier_carrier", 440.0, nullptr);
    apvts.state.setProperty("operator_carrier_modulator", 220.0, nullptr);
    apvts.state.setProperty("operator_carrier_depth", 1.0, nullptr);
}
