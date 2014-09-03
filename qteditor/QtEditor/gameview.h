#pragma once


#include <QDockWidget>


namespace Lumix
{
	class WorldEditor;
	class PipelineInstance;
}

namespace Ui
{
	class GameView;
}

class GameView : public QDockWidget
{
	Q_OBJECT

public:
	explicit GameView(QWidget* parent = NULL);
	virtual ~GameView();

	QWidget* getContentWidget() const;
	void setPipeline(Lumix::PipelineInstance& pipeline) { m_pipeline = &pipeline; }
	void setWorldEditor(Lumix::WorldEditor& editor) { m_editor = &editor; }

private slots:
	void on_playButton_clicked();

private:
	virtual void resizeEvent(QResizeEvent*) override;

private:
	Ui::GameView* m_ui;
	Lumix::PipelineInstance* m_pipeline;
	Lumix::WorldEditor* m_editor;
};

