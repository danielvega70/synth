#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_audio_utils/juce_audio_utils.h>
#include <cmath>

class FmSynth : public juce::Synthesiser
{
public:
    FmSynth()
    {
        // Definir el operador de modulación
        opMod.index = 0.5;
        opMod.carrier = 440.0;
        opMod.modulator = 220.0;
        opMod.depth = 1.0;

        // Definir el operador de portadora
        opCarrier.index = 1.0;
        opCarrier.carrier = 440.0;
        opCarrier.modulator = 220.0;
        opCarrier.depth = 1.0;

        // Agregar los operadores al sintetizador
        addVoice(new juce::SynthesiserVoice());
        addSound(new juce::SynthesiserSound());
    }

    // Generar una muestra
    float processSample(float modInput)
    {
        // Obtener la salida del operador de modulación
        float modOutput = opMod.processSample(modInput);

        // Obtener la salida del operador de portadora
        float carrierOutput = opCarrier.processSample(modOutput);

        return carrierOutput;
    }

    // Clase para un operador de modulación
    class Operator
    {
    public:
        float index; // Índice de modulación
        float carrier; // Frecuencia de la portadora
        float modulator; // Frecuencia del modulador
        float depth; // Profundidad de la modulación

        // Generar una muestra del operador
        float processSample(float modInput)
        {
            float modulatedFrequency = carrier + modulator * modInput * depth;
            float sample = std::sin(2 * juce::MathConstants<float>::pi * modulatedFrequency / juce::JUCESampleRate);
            return index * sample;
        }
    };

private:
    Operator opMod; // Operador de modulación
    Operator opCarrier; // Operador de portadora
};

class FmSynthAudioProcessor : public juce::AudioProcessor
{
public:
    FmSynthAudioProcessor()
    {
        synth.reset(new FmSynth());
    }

    // Métodos de AudioProcessor
    juce::AudioProcessorEditor* createEditor() override { return nullptr; }
    bool hasEditor() const override { return false; }
    const juce::String getName() const override { return "FM Synth"; }
    bool acceptsMidi() const override { return true; }
    bool producesMidi() const override { return true; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int index) override {}
    const juce::String getProgramName(int index) override { return ""; }
    void changeProgramName(int index, const juce::String& newName) override {}

    void prepareToPlay(double sampleRate, int) override
    {
        synth->setCurrentPlaybackSampleRate(sampleRate);
    }

    void releaseResources() override {}

    void
